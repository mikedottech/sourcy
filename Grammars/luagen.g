//////////////////////////////////////////
//										//
// Tree Grammar for M.U.G.E.N 			//
// cns / cmd format						//
//										//
// This grammar will generate LUA code  //
// from a cns/cmd AST for the CSW       //
// runtime.                             //
//										//
// 2012 - Miguel Angel Exposito			//
// <radexx[at]gmail.com>				//
//////////////////////////////////////////

tree grammar luagen;

options
{
	tokenVocab=cns;
	language=C;
	ASTLabelType=pANTLR3_BASE_TREE;
	k=3;
}

@treeparser::header {
#	include "CNSDataType.h"
#	include "CNSGrammarInclude.h"
#	include "LUAGenSemanticActions.h"
#	include "CNSCodeBlockType.h"
#	include "Helpers.h"
#	include "PreEval.h"
#	include "CNSControllerUsage.h"
#	include "math.h"	// for pow()

#define SPECIAL_CNT_NONE			0
#define SPECIAL_CNT_VARSET			1
#define SPECIAL_CNT_VARADD			2
#define SPECIAL_CNT_PARENTVARSET	3
#define SPECIAL_CNT_PARENTVARADD	4

}

@members {

	bool logXOR(bool a, bool b)
	{
		return (!a && b) || (a && !b);
	}

	preeval_op_type_t getOpType(cns_Datatype_t left, cns_Datatype_t right)
	{
		if(left == CDT_INT && right == CDT_INT)
			return OP_INT_INT;
		else if(left == CDT_INT && right == CDT_FLOAT)
			return OP_INT_FLOAT;
		else if(left == CDT_FLOAT && right == CDT_INT)
			return OP_FLOAT_INT;
		else if(left == CDT_FLOAT && right == CDT_FLOAT)
			return OP_FLOAT_FLOAT;
		return OP_UNDEFINED;
	}
	
#define BINARY_OP_ARITH_PREEVAL(PDST, OPTYPE, OPERATOR, LEFTPE, RIGHTPE) \
	switch(OPTYPE)\
	{\
		case OP_INT_INT:\
			PDST->data.intVal = LEFTPE.data.intVal OPERATOR RIGHTPE.data.intVal;\
		break;\
		case OP_FLOAT_FLOAT:\
			PDST->data.floatVal = LEFTPE.data.floatVal OPERATOR RIGHTPE.data.floatVal;\
		break;\
		case OP_INT_FLOAT:\
			PDST->data.floatVal = LEFTPE.data.intVal OPERATOR RIGHTPE.data.floatVal;\
		break;\
		case OP_FLOAT_INT:\
			PDST->data.floatVal = LEFTPE.data.floatVal OPERATOR RIGHTPE.data.intVal;\
		break;\
	}\
	PDST->valType = LEFTPE.valType == CDT_FLOAT || RIGHTPE.valType == CDT_FLOAT ? CDT_FLOAT : CDT_INT;\

#define BINARY_OP_LOGIC_PREEVAL(PDST, OPTYPE, OPERATOR, LEFTPE, RIGHTPE) \
	switch(OPTYPE)\
	{\
		case OP_INT_INT:\
			PDST->data.intVal = LEFTPE.data.intVal OPERATOR RIGHTPE.data.intVal;\
		break;\
		case OP_FLOAT_FLOAT:\
			PDST->data.intVal = LEFTPE.data.floatVal OPERATOR RIGHTPE.data.floatVal;\
		break;\
		case OP_INT_FLOAT:\
			PDST->data.intVal = LEFTPE.data.intVal OPERATOR RIGHTPE.data.floatVal;\
		break;\
		case OP_FLOAT_INT:\
			PDST->data.intVal = LEFTPE.data.floatVal OPERATOR RIGHTPE.data.intVal;\
		break;\
	}\
	PDST->valType = CDT_INT;\

#define BINARY_OP_BIT_PREEVAL(PDST, OPTYPE, OPERATOR, LEFTPE, RIGHTPE) \
	switch(OPTYPE)\
	{\
		case OP_INT_INT:\
			PDST->data.intVal = LEFTPE.data.intVal OPERATOR RIGHTPE.data.intVal;\
		break;\
		case OP_FLOAT_FLOAT:\
			PDST->data.intVal = (int)LEFTPE.data.floatVal OPERATOR (int)RIGHTPE.data.floatVal;\
		break;\
		case OP_INT_FLOAT:\
			PDST->data.intVal = LEFTPE.data.intVal OPERATOR (int)RIGHTPE.data.floatVal;\
		break;\
		case OP_FLOAT_INT:\
			PDST->data.intVal = (int)LEFTPE.data.floatVal OPERATOR RIGHTPE.data.intVal;\
		break;\
	}\
	PDST->valType = CDT_INT;\

#define UNARY_OP_LOGIC_PREEVAL(PDST, DATATYPE, OPERATOR, PE) \
	switch(DATATYPE)\
	{\
		case CDT_INT:\
			PDST->data.intVal = OPERATOR PE.data.intVal;\
		break;\
		case CDT_FLOAT:\
			PDST->data.floatVal = (float) (OPERATOR PE.data.floatVal);\
		break;\
	}\
	PDST->valType = DATATYPE;\

	void appendPreEvalValue(pANTLR3_STRING s, preeval_t pe)
	{
		char buffer[100];
		if(pe.valType == CDT_INT)
		{
			sprintf(buffer, "\%d", pe.data.intVal);
		} else if(pe.valType == CDT_FLOAT)
		{
			sprintf(buffer, "\%g", pe.data.floatVal);
		}
		s->append8(s, buffer);
	}

	void appendExprPE(pANTLR3_STRING s, luagen_expr_return e)
	{
		if(e.p.isConstant)
		{
			appendPreEvalValue(s, e.p);
		} else {
			s->appendS(s, e.s);
		}
	}
	
	void preevalUnary(char *op, preeval_t *pe)
	{
		if(pe->isConstant)
		{
			if(!strcmp(op, "!"))
			{
				UNARY_OP_LOGIC_PREEVAL(pe, pe->valType, !, (*pe))
			} else if(!strcmp(op, "~"))
			{
				if(pe->valType != CDT_INT)
				{
					// This should be an error
					pe->isConstant = false;
				} else {
					pe->data.intVal = ~(pe->data.intVal);
				}
			} else if(!strcmp(op, "-"))
			{
				if(pe->valType != CDT_INT)
				{
					// This should be an error
					pe->isConstant = false;
				} else {
					pe->data.intVal = -(pe->data.intVal);
				}
			}
		}
	}

	ANTLR3_BOOLEAN generateBinaryOp(pANTLR3_STRING s, char * op, pANTLR3_STRING e1, pANTLR3_STRING e2,
						  preeval_t *preeval_out, preeval_t preeval_1, preeval_t preeval_2)
	{
		bool resultIsConstant			= preeval_1.isConstant && preeval_2.isConstant;
		
		preeval_op_type_t opType		= getOpType(preeval_1.valType, preeval_2.valType);
				
		preeval_out->isConstant = resultIsConstant;
		//preeval_out->valType	= resultType;
		
	
		// Possible cases
		//
		// float (op) int
		// int   (op) float
		// int   (op) int
		// float (op) float
		
		
		if(!strcmp(op, "^^"))	// Logical XOR (custom implemented)
		{
			// Do preevaluation
			if(resultIsConstant)
			{
				switch(opType)
				{
					case OP_INT_INT:
						preeval_out->data.intVal = logXOR(preeval_1.data.intVal, preeval_2.data.intVal);
					break;
					case OP_FLOAT_FLOAT:
						preeval_out->data.intVal = logXOR((int)preeval_1.data.floatVal, (int)preeval_2.data.intVal);
					break;
					case OP_INT_FLOAT:
						preeval_out->data.intVal = logXOR(preeval_1.data.intVal, (int)preeval_2.data.floatVal);
					break;
					case OP_FLOAT_INT:
						preeval_out->data.intVal = logXOR((int)preeval_1.data.floatVal, preeval_2.data.intVal);
					break;
				}
				preeval_out->valType = CDT_INT;
				appendPreEvalValue(s, *preeval_out);
			} else {
				s->append8(s, "Utils.logXOR(");
				s->appendS(s, e1);
				s->append8(s, ", ");
				s->appendS(s, e2);
				s->append8(s, ")");
			}
		} else if(!strcmp(op, "|")) // Bit OR
		{
			// Do preevaluation
			if(resultIsConstant)
			{
				BINARY_OP_BIT_PREEVAL(preeval_out, opType, |, preeval_1, preeval_2)
				appendPreEvalValue(s, *preeval_out);
			} else {
				/*
					s->append8(s, "bit.bor(");
					s->appendS(s, e1);
					s->append8(s, ", ");
					s->appendS(s, e2);
					s->append8(s, ")");
				*/
				s->append8(s, "(");
				s->appendS(s, e1);
				s->append8(s, " | ");
				s->appendS(s, e2);
				s->append8(s, ")");				
			}			
			
		} else if(!strcmp(op, "^")) // Bit XOR
		{
			// Do preevaluation
			if(resultIsConstant)
			{
				BINARY_OP_BIT_PREEVAL(preeval_out, opType, ^, preeval_1, preeval_2)
				appendPreEvalValue(s, *preeval_out);
			} else {
				/*
					s->append8(s, "bit.bxor(");
					s->appendS(s, e1);
					s->append8(s, ", ");
					s->appendS(s, e2);
					s->append8(s, ")");
				*/
				s->append8(s, "(");
				s->appendS(s, e1);
				s->append8(s, " ^^ ");
				s->appendS(s, e2);
				s->append8(s, ")");				

			}
		} else if(!strcmp(op, "&")) // Bit AND
		{
			// Do preevaluation
			if(resultIsConstant)
			{
				BINARY_OP_BIT_PREEVAL(preeval_out, opType, &, preeval_1, preeval_2)
				appendPreEvalValue(s, *preeval_out);
			} else {
				/*
					s->append8(s, "bit.band(");
					s->appendS(s, e1);
					s->append8(s, ", ");
					s->appendS(s, e2);
					s->append8(s, ")");
				*/
				s->append8(s, "(");
				s->appendS(s, e1);
				s->append8(s, " & ");
				s->appendS(s, e2);
				s->append8(s, ")");				
			}
		} else if(!strcmp(op, "||")) {
			// Do preevaluation
			if(resultIsConstant)
			{
				BINARY_OP_LOGIC_PREEVAL(preeval_out, opType, ||, preeval_1, preeval_2)
				appendPreEvalValue(s, *preeval_out);
			} else {
				s->append8(s, "(");
				s->appendS(s, e1);			
				s->append8(s, " or ");
				s->appendS(s, e2);
				s->append8(s, ")");
			}
		} else if(!strcmp(op, "&&")) {
			// Do preevaluation
			if(resultIsConstant)
			{
				BINARY_OP_BIT_PREEVAL(preeval_out, opType, &&, preeval_1, preeval_2)
				appendPreEvalValue(s, *preeval_out);
			} else {
				s->append8(s, "(");
				s->appendS(s, e1);			
				s->append8(s, " and ");
				s->appendS(s, e2);
				s->append8(s, ")");
			}			
		} else if(!strcmp(op, "**")) {
			// Do preevaluation
			if(resultIsConstant)
			{
				switch(opType)
				{
					case OP_INT_INT:
						preeval_out->data.floatVal = (float)pow(preeval_1.data.intVal, preeval_2.data.intVal);
					break;
					case OP_FLOAT_FLOAT:
						preeval_out->data.floatVal = (float)pow(preeval_1.data.floatVal, preeval_2.data.intVal);
					break;
					case OP_INT_FLOAT:
						preeval_out->data.floatVal = (float)pow(preeval_1.data.intVal, preeval_2.data.floatVal);
					break;
					case OP_FLOAT_INT:
						preeval_out->data.floatVal = (float)pow(preeval_1.data.floatVal, preeval_2.data.intVal);
					break;
				}
				preeval_out->valType = CDT_FLOAT;
				appendPreEvalValue(s, *preeval_out);
			} else {
				s->append8(s, "(");
				s->appendS(s, e1);			
				s->append8(s, " ^ ");
				s->appendS(s, e2);
				s->append8(s, ")");
			}			
		} else if(!strcmp(op, "=")) {
			// Do preevaluation
			if(resultIsConstant)
			{
				BINARY_OP_LOGIC_PREEVAL(preeval_out, opType, ==, preeval_1, preeval_2)
				appendPreEvalValue(s, *preeval_out);
			} else {
				s->append8(s, "(");
				s->appendS(s, e1);			
				s->append8(s, " == ");
				s->appendS(s, e2);
				s->append8(s, ")");
			}				
		} else if(!strcmp(op, "!=")) {
			// Do preevaluation
			if(resultIsConstant)
			{
				BINARY_OP_LOGIC_PREEVAL(preeval_out, opType, !=, preeval_1, preeval_2)
				appendPreEvalValue(s, *preeval_out);
			} else {
				s->append8(s, "(");
				s->appendS(s, e1);			
				s->append8(s, " ~= ");
				s->appendS(s, e2);
				s->append8(s, ")");
			}
		} else {
			// Do preevaluation
			if(resultIsConstant)
			{
				if(!strcmp(op, "+"))
				{
					BINARY_OP_ARITH_PREEVAL(preeval_out, opType, +, preeval_1, preeval_2)
					appendPreEvalValue(s, *preeval_out);
				} else if(!strcmp(op, "-"))
				{
					BINARY_OP_ARITH_PREEVAL(preeval_out, opType, -, preeval_1, preeval_2)
					appendPreEvalValue(s, *preeval_out);
				} else if(!strcmp(op, "*"))
				{
					BINARY_OP_ARITH_PREEVAL(preeval_out, opType, *, preeval_1, preeval_2)
					appendPreEvalValue(s, *preeval_out);
				} else if(!strcmp(op, "/"))
				{
					if(preeval_2.valType == CDT_FLOAT && preeval_2.data.floatVal == 0 ||
					   preeval_2.valType == CDT_INT && preeval_2.data.intVal == 0)
					{
						fprintf(stderr, "ERROR: Explicit division by 0 !");
						return ANTLR3_FALSE;
					}
					BINARY_OP_ARITH_PREEVAL(preeval_out, opType, /, preeval_1, preeval_2)
					appendPreEvalValue(s, *preeval_out);
				}
			} else {
				s->append8(s, "(");
				s->appendS(s, e1);
				s->append8(s, " ");
				s->append8(s, op);
				s->append8(s, " ");
				s->appendS(s, e2);
				s->append8(s, ")");
			}
		}
		return ANTLR3_TRUE;
	}

	
	void generateUnaryOp(pANTLR3_STRING s, char *op, pANTLR3_STRING e)
	{
		if(!strcmp(op, "~"))
		{
			//s->append8(s, "bit.bnot(");
			s->append8(s, "~");
			s->appendS(s, e);
			s->append8(s, ")");
		} else if(!strcmp(op, "!")) {
			s->append8(s, "not ");
			s->appendS(s, e);
		} else { // - (MINUS)
			s->append8(s, op);
			s->appendS(s, e);
		}
	}
	
	void generateIntervalOp(pANTLR3_STRING s, pANTLR3_STRING op, pANTLR3_STRING lhs, pANTLR3_STRING leftLim, pANTLR3_STRING rightLim, pANTLR3_STRING minVal, pANTLR3_STRING maxVal)
	{
		s->append8(s, "(");		
		if(!strcmp(op->chars, "!="))
		{
			s->append8(s, "not ");
		}
		s->append8(s, "Utils.inInterval(");
		s->appendS(s, lhs);
		s->append8(s, ", \"");
		s->appendS(s, leftLim);
		s->append8(s, "\", ");
		s->appendS(s, minVal);
		s->append8(s, ", ");
		s->appendS(s, maxVal);
		s->append8(s, ", \"");
		s->appendS(s, rightLim);
		s->append8(s, "\"))");		
	}

	void generateTriggerRedir(pANTLR3_STRING s, pANTLR3_STRING redir, pANTLR3_STRING param, pANTLR3_STRING triggercall)
	{
		// Convert the redir to uppercase
		
		char * REDIR = strdup(redir->chars);
		
		char_string_toUpperSelf(REDIR);
		
		if(!strcmp(REDIR, "PARENT"))
		{
			s->append8(s, "getParent");
		} else if(!strcmp(REDIR, "ROOT"))
		{
			s->append8(s, "getRoot");
		} else if(!strcmp(REDIR, "PARTNER"))
		{
			s->append8(s, "getPartner");
		} else if(!strcmp(REDIR, "HELPER"))		
		{
			s->append8(s, "getHelper");
		} else if(!strcmp(REDIR, "TARGET"))
		{
			s->append8(s, "getTarget");
		} else if(!strcmp(REDIR, "ENEMY"))
		{
			s->append8(s, "getEnemy");
		} else if(!strcmp(REDIR, "ENEMYNEAR"))
		{
			s->append8(s, "getEnemyNear");
		} else if(!strcmp(REDIR, "PLAYERID"))
		{
			s->append8(s, "getPlayerID");
		}
		
		s->append8(s, "(");
		// Insert param here if valid
		if(param != NULL)
		{
			s->appendS(s, param);
		}
		s->append8(s, ")");
		s->appendS(s, triggercall);
		
		free(REDIR);
	}	
	
	void appendEqualityOp(pANTLR3_STRING s, pANTLR3_STRING op)
	{
		if(!strcmp(op->chars, "="))
		{
			s->append8(s, " == ");
		} else if(!strcmp(op->chars, "!="))
		{
			s->append8(s, " ~= ");
		}
	}
	
	void appendNumberCompOp(pANTLR3_STRING s, pANTLR3_STRING op)
	{
		if(!strcmp(op->chars, "="))
		{
			s->append8(s, " == ");
		} else if(!strcmp(op->chars, "!="))
		{
			s->append8(s, " ~= ");
		} else {
			s->append8(s, " ");
			s->appendS(s, op);
			s->append8(s, " ");
		}
	}
	
	void regularizeLHS(pANTLR3_STRING dst, pANTLR3_STRING src)
	{
		unsigned int i;
		dst->setS(dst, src);
		for(i = 0; i < src->len; ++i)
		{			
			//dst->chars[i] = tolower(src->chars[i]);
			if(src->chars[i] == '.')
			{
				dst->chars[i] = '_';
			}
		}
	}
	
	void strToLower(pANTLR3_STRING dst, pANTLR3_STRING src)
	{
		unsigned int i;
		dst->setS(dst, src);
		for(i = 0; i < src->len; ++i)
		{			
			dst->chars[i] = tolower(src->chars[i]);
		}
	}
	
	void regularizeWSpaceAttr(pANTLR3_STRING dst, pANTLR3_STRING src)
	{
		unsigned int i;
		dst->setS(dst, src);
		for(i = 0; i < src->len; ++i)
		{			
			dst->chars[i] = tolower(src->chars[i]);
			if(src->chars[i] == '.')
			{
				dst->chars[i] = '_';
			}
		}
	}
}

root
@init
{
	luagenSemanticActions_init();
}
@after
{
	luagenSemanticActions_end();
}	: (state
	| infoBlock
	| cmdDefBlock 
	| remapBlock 
	| defaultsBlock
	)+
	;

infoBlock
	: ^(INFOBLOCK
		idSel
		{
			luagenSemanticActions_beginStateCodeBlock(CBT_INFO, $idSel.text->chars);
		}
		{			
			pANTLR3_STRING tmp = luagenSemanticActions_getNewString();
			pANTLR3_STRING tmp2 = luagenSemanticActions_getNewString();
			strToLower(tmp2, $idSel.text);
			tmp->set8(tmp, luagenSemanticActions_getEntityName());
			tmp->append8(tmp, ".m_constants[\"");
			tmp->appendS(tmp, tmp2);
			tmp->append8(tmp, "\"] = {");
			luagenSemanticActions_appendCodeLine(tmp);
			luagenSemanticActions_incInd();
		}
		(is=infoStmt
		{
			luagenSemanticActions_appendCodeLine($is.s);
		}
		)+		
		{
			luagenSemanticActions_decInd();
			luagenSemanticActions_appendCodeLineC("}");
		}
		)
		{
			luagenSemanticActions_endCodeBlock();
		}
	;
	
infoStmt returns [pANTLR3_STRING s]
	: 
	{ $s = luagenSemanticActions_getNewString(); }
	(^(ASSIGNSTMT 
		{
			$s->append8($s, "[\"");
		} (idSel
			{
				pANTLR3_STRING tmp = luagenSemanticActions_getNewString();				
				strToLower(tmp, $idSel.text);
				$s->appendS($s, tmp);
			}
			| reservedKWAsLHS
				{
					$s->appendS($s, $reservedKWAsLHS.text);
				}
			)
		{
			$s->append8($s, "\"] = ");
		}
		infoStmtRHSNumbers
		{
			if($infoStmtRHSNumbers.count > 1)
			{
				$s->append8($s, "{");
			}
			$s->appendS($s, $infoStmtRHSNumbers.s);
			if($infoStmtRHSNumbers.count > 1)
			{
				$s->append8($s, "}");
			}
		}
		)
	|	^(ASSIGNSTMT ^('VICTORY' vNum=INTEGER) vStr=STRING_LITERAL)
		{
			$s->append8($s, "[\"victory_");
			$s->appendS($s, $vNum.text);
			$s->append8($s, "\"] = ");
			$s->appendS($s, $vStr.text);
		}
	)
	{
		if(LA(1) == ASSIGNSTMT)
		{
			$s->append8($s, ",");
		}
	}
	;

infoStmtRHSNumbers returns [int count, pANTLR3_STRING s]
	:
	{	$count = 0; 
		$s = luagenSemanticActions_getNewString();
	}
		rhs=signedNumber
		{
			$s->appendS($s, $rhs.s);
			++$count;
		}
		(rhs=signedNumber
		{
			$s->append8($s, ", ");
			$s->appendS($s, $rhs.s);
			++$count;
		}
		)*
		
	;

state
@after
{
	luagenSemanticActions_decInd();
	luagenSemanticActions_appendCodeLineC("end");
	luagenSemanticActions_endCodeBlock();
}	:	^(STATEDEF signedInteger	{luagenSemanticActions_beginStateCodeBlock(CBT_STATE, $signedInteger.s->chars);}
		{	// State function header
			{
				pANTLR3_STRING s = luagenSemanticActions_getNewString();
				s->set8(s, "function ");
				s->append8(s, luagenSemanticActions_getEntityName());
				s->append8(s, ":");
				s->append8(s, luagenSemanticActions_getCurCodeBlockID());
				s->append8(s, "()");
				luagenSemanticActions_appendCodeLine(s);
				luagenSemanticActions_incInd();
			}
		}
		{	// State initialization
			{
				luagenSemanticActions_appendCodeLineC("-- State initialization");
				luagenSemanticActions_appendCodeLineC("self:setStateParams");
				luagenSemanticActions_appendCodeLineC("{");
//				luagenSemanticActions_appendCodeLineC("if self:time() == 0 then");
				luagenSemanticActions_incInd();
			}
		}
	    (stateAssignStmt
			{
				luagenSemanticActions_appendCodeLine($stateAssignStmt.s);
			}
	    )*
	    {	// End of state initialization
			{
				luagenSemanticActions_decInd();
				luagenSemanticActions_appendCodeLineC("}");
//				luagenSemanticActions_appendCodeLineC("end");
			}
		}
			(
				stateCntBlock 
					
			)*
	    )
	;
	
stateAssignStmt returns [pANTLR3_STRING s]
scope
{
	unsigned int nArgs;
}
	:
	{ $s = luagenSemanticActions_getNewString(); }
	( 	^(TYPE typeStr=attr_string)
		{
			{
				s->set8(s, "stateType = \"");
				s->appendS(s, $typeStr.text);
				s->append8(s, "\",");				
			}
		}
	| 	^(PHYSICS physicsStr=attr_string)												 
		{
			{
				s->set8(s, "physics = \"");
				s->appendS(s, $physicsStr.text);
				s->append8(s, "\",");				
			}
		}
	| 	^(MOVETYPE moveTypeStr=attr_string)
		{
			{
				s->set8(s, "moveType = \"");
				s->appendS(s, $moveTypeStr.text);
				s->append8(s, "\",");				
			}
		}
	|	^(ASSIGNSTMT lhs=assignStmtLHS
			{
				//s->set8(s, "self:");
				s->set8(s, "");
				// Set the right name for the 
				// setter function				
				s->append8(s, (const char*) luagenSemanticActions_getNameForStateInit($lhs.text, &($stateAssignStmt::nArgs)));
				s->append8(s, " = ");
				if($stateAssignStmt::nArgs > 1)
					s->append8(s, "{");
			}
		(rhs=argValue
			{
				s->appendS(s, $rhs.s);
			}
		(COMMA
			{
				s->append8(s, ", ");
			}
		)?)+
		{ 
			if($stateAssignStmt::nArgs > 1)
				s->append8(s, "}");
			s->append8(s, ","); }
		)		// RHS
	)
	;
	
assignStmtLHS returns [pANTLR3_STRING s]
	: 
	{ $s = luagenSemanticActions_getNewString(); }
	( idSel				{$s->appendS($s, $idSel.text);}
	| reservedKWAsLHS	{$s->appendS($s, $reservedKWAsLHS.text);}
	| varReference		{$s->appendS($s, $varReference.s);}
	)
	;

argValue returns [pANTLR3_STRING s]
	:
	{ $s = luagenSemanticActions_getNewString(); }
	(	(S|F)=>(id=S|id=F)		{ $s->append8($s, "\""); $s->appendS($s, $id.text); $s->append8($s, "\"");}
	|	argValueAtom			{ $s->appendS($s, $argValueAtom.s); }
	|	^(EXPRREDIR (redirMod=S|redirMod=F) redirExpr=expr)
		{
			$s->append8($s, "{\"");
			$s->appendS($s, $redirMod.text);
			$s->append8($s, "\", ");
			appendExprPE(s, redirExpr);
			/*$s->appendS($s, $redirExpr.s);			*/
			$s->append8($s, "}");
		}
	)
	;

argValueAtom returns [pANTLR3_STRING s]
	:
	{ $s = luagenSemanticActions_getNewString(); }
	( e=expr				{ appendExprPE(s, e); /* $s->appendS($s, $expr.s);*/ }
	| str=STRING_LITERAL	{ $s->appendS($s, $str.text); }
	| cntArgKeywords		{ $s->append8($s, "\""); $s->appendS($s, $cntArgKeywords.text); $s->append8($s, "\"");}
	| id=ID					{ $s->append8($s, "\""); $s->appendS($s, $id.text); $s->append8($s, "\""); }
	)
	;
	
	
stateCntBlock	// Tree sub-elements here should appear according to the order defined in CnsControllerElement::classify()
scope
{
	cnsControllerUsage_t *pControllerUsage;
	int specialCnt;
}	:	
		^(st=STATE 
			{
				// Get the controller and the used syntax
				$stateCntBlock::pControllerUsage = (cnsControllerUsage_t *)($st)->u;
				$stateCntBlock::specialCnt = SPECIAL_CNT_NONE;
				// Don't generate anything if it's a null controller
				if(!strcmp($stateCntBlock::pControllerUsage->pSignature->UCName, "NULL"))
				{
					luagenSemanticActions_muteOutput();
				} else if(!strcmp($stateCntBlock::pControllerUsage->pSignature->UCName, "VARSET") &&
					$stateCntBlock::pControllerUsage->usedSyntax >= 2)
				{
					$stateCntBlock::specialCnt = SPECIAL_CNT_VARSET;
				} else if(!strcmp($stateCntBlock::pControllerUsage->pSignature->UCName, "VARADD") &&
							$stateCntBlock::pControllerUsage->usedSyntax >= 2)
				{
					$stateCntBlock::specialCnt = SPECIAL_CNT_VARADD;
				} else if(!strcmp($stateCntBlock::pControllerUsage->pSignature->UCName, "PARENTVARSET") &&
							$stateCntBlock::pControllerUsage->usedSyntax >= 2)
				{
					$stateCntBlock::specialCnt = SPECIAL_CNT_PARENTVARSET;
				} else if(!strcmp($stateCntBlock::pControllerUsage->pSignature->UCName, "PARENTVARADD") &&
						$stateCntBlock::pControllerUsage->usedSyntax >= 2)
				{
					$stateCntBlock::specialCnt = SPECIAL_CNT_PARENTVARADD;
				}
			}
			stateCntName
			^(TYPE (typeName=ID | typeName='HELPER' | typeName='CHANGEANIM2')
				{
					luagenSemanticActions_appendCodeLineC("");
					luagenSemanticActions_appendCodeLineC("-- State controller");
				}
			)
			
			// Common attrs
			// scAssignStmt*
			
			(triggerAllBlock
				{luagenSemanticActions_appendCodeLine($triggerAllBlock.s);
				 luagenSemanticActions_incInd();
				}
			)?
			(triggerBlock
				{luagenSemanticActions_appendCodeLine($triggerBlock.s);
				 luagenSemanticActions_incInd();
				}
			)
						
			// Generate controller call body
			{
				pANTLR3_STRING tmp;
				if($stateCntBlock::specialCnt == SPECIAL_CNT_NONE)
				{
					tmp = luagenSemanticActions_getNewString();
					tmp->set8(tmp, "self:");
					tmp->append8(tmp, $stateCntBlock::pControllerUsage->pSignature->properName);
					tmp->append8(tmp, " {");
					luagenSemanticActions_appendCodeLine(tmp);
					luagenSemanticActions_incInd();
				} else {
				/*
					switch($stateCntBlock::specialCnt)
					{
						case SPECIAL_CNT_VARSET:
							luagenSemanticActions_appendCodeLineC("self:varSet{");
						break;
						case SPECIAL_CNT_VARADD:
							luagenSemanticActions_appendCodeLineC("self:varAdd{");
						break;
						case SPECIAL_CNT_PARENTVARSET:
							luagenSemanticActions_appendCodeLineC("self:parentVarSet{");
						break;
						case SPECIAL_CNT_PARENTVARADD:
							luagenSemanticActions_appendCodeLineC("self:parentVarAdd{");
						break;
					}
					*/
					luagenSemanticActions_appendCodeLineC("if self:canExecuteController{");					
					luagenSemanticActions_incInd();
				}
			}
			
			scAssignStmt*
			
			{
				if($stateCntBlock::specialCnt == SPECIAL_CNT_NONE)
				{
					luagenSemanticActions_decInd();
					luagenSemanticActions_appendCodeLineC("}");
				}			
				// Generate any needed end's and decrement indentation
				luagenSemanticActions_closeBlocksToLevel(1);
				// Un-mute the output in case it was muted previously
				luagenSemanticActions_unMuteOutput();
			}
		 )		
	;

triggerAllBlock returns [pANTLR3_STRING s]
	:
	{ $s = luagenSemanticActions_getNewString(); }
	(
		{
			$s->append8($s, "if ");
		}

		^(TRIGGERSTMT ALL e1=expr) 
			{
				$s->appendS($s, $e1.s);
			}
			
		(
			^(TRIGGERSTMT ALL en=expr)
			{
				$s->append8($s, " and ");
				$s->appendS($s, $en.s);
			}
		)*
		
		{
			$s->append8($s, " then");
		}
	)
				
	;
	
triggerBlock returns [pANTLR3_STRING s]
scope
{
	pANTLR3_STRING triggerGroup;
}
@init
{
	$triggerBlock::triggerGroup = 0;
}
	:
		{ $s = luagenSemanticActions_getNewString(); }
	(
		{
			$s->append8($s, "if ");
		}

		^(TRIGGERSTMT i=INTEGER e1=expr) 
			{
				$triggerBlock::triggerGroup = $i.text;
				appendExprPE(s, e1);
			}
			
		(
			^(TRIGGERSTMT i2=INTEGER en=expr)
			{
				// Have we changed the trigger group?
				if($triggerBlock::triggerGroup->compareS($triggerBlock::triggerGroup, $i2.text))
				{
					$triggerBlock::triggerGroup = $i2.text;
					$s->append8($s, " or ");
				} else {				
					$s->append8($s, " and ");
				}
				$s->appendS($s, $en.s);
			}
		)*
		
		{
			$s->append8($s, " then");
		}
	)
	;

stateCntName
	:	^(STATECNTID id=(options {greedy = false; }: .)*)
	;
	
stateCntStmt
	:	triggerStmt | scAssignStmt
	;
	
scAssignStmtLHS
	:	idSel
	|	reservedKWAsLHS	
	;
	
scAssignStmt // returns [pANTLR3_STRING lhs, pANTLR3_STRING rhs]
scope
{
	pANTLR3_STRING buffer;
}
@init
{
	mod = NULL;
}
	:
	{ $scAssignStmt::buffer = luagenSemanticActions_getNewString(); }
	(
		^(ASSIGNSTMT v=varReference e=expr)			// var/fvar/sysvar/sysfvar as LHS
		{
			pANTLR3_STRING b = $scAssignStmt::buffer;
			b->append8(b, "self.");
			if($stateCntBlock::specialCnt == SPECIAL_CNT_VARADD)
			{
				luagenSemanticActions_appendCodeLineC("} then");
				b->appendS(b, $v.s);
				b->append8(b, " = self.");
				b->appendS(b, $v.s);
				b->append8(b, " + ");
				b->appendS(b, $e.s);
			} else if($stateCntBlock::specialCnt == SPECIAL_CNT_PARENTVARSET)
			{
				luagenSemanticActions_appendCodeLineC("} then");
				b->append8(b, "getParent().");
				b->appendS(b, $v.s);
				b->append8(b, " = ");
				b->appendS(b, $e.s);
			} else if($stateCntBlock::specialCnt == SPECIAL_CNT_PARENTVARADD)			
			{
				luagenSemanticActions_appendCodeLineC("} then");
				b->append8(b, "getParent().");
				b->appendS(b, $v.s);
				b->append8(b, " = self:getParent().");
				b->appendS(b, $v.s);
				b->append8(b, " + ");
				b->appendS(b, $e.s);
			} else if($stateCntBlock::specialCnt == SPECIAL_CNT_VARSET) {
				luagenSemanticActions_appendCodeLineC("} then");
				b->appendS(b, $v.s);
				b->append8(b, " = ");
				b->appendS(b, $e.s);
			} else {
				b->appendS(b, $v.s);
				b->append8(b, " = ");
				b->appendS(b, $e.s);
			}
			luagenSemanticActions_appendCodeLine(b);			
		}
	|	^(ASSIGNSTMT lhs=scAssignStmtLHS scArgList)
		{
			pANTLR3_STRING b = $scAssignStmt::buffer;
			pANTLR3_STRING b_reg = luagenSemanticActions_getNewString();
			
			b_reg->set8(b_reg, luagenSemanticActions_getNameForControllerArg($stateCntBlock::pControllerUsage, $lhs.text));
			
			regularizeLHS(b_reg, b_reg);
			b->appendS(b, b_reg);
			b->append8(b, " = ");
			if($scArgList.nArgs > 1)
			{
				b->append8(b, "{");
			}			
			b->appendS(b, $scArgList.s);
			if($scArgList.nArgs > 1)
			{
				b->append8(b, "}");
			}
			if(LA(1) == ASSIGNSTMT)	b->append8(b, ",");
			luagenSemanticActions_appendCodeLine(b);
		}
	|	^(ASSIGNSTMT lhsH=HITFLAG
					id=ID 
					(mod=PLUS|mod=MINUS)?)
		{
			pANTLR3_STRING b = $scAssignStmt::buffer;
			b->append8(b, luagenSemanticActions_getNameForControllerArg($stateCntBlock::pControllerUsage, $lhsH.text));
			b->append8(b, " = \"");
			b->appendS(b, $id.text);
			if(mod)	b->appendS(b, $mod.text);			
			if(LA(1) == ASSIGNSTMT)	b->append8(b, ",");
		}
	)
	;

scArgList returns [pANTLR3_STRING s, int nArgs]
	:
	{ $s = luagenSemanticActions_getNewString(); 
	  $nArgs = 0;
	}
	(
		rhs=argValue
		{
			$s->appendS($s, $argValue.s);
			++$nArgs;
		}
		(more1=moreScArgList
		{
			$s->appendS($s, $more1.s);
			++$nArgs;
		})*
	|	{
			$s->append8($s, "\"\"");
		}
		(more2=moreScArgList
		{			
			$s->appendS($s, $more2.s);
			++$nArgs;
		}
		)+
	|	{
			$s->append8($s, "\"\"");
			++$nArgs;
		}
	)
	;

moreScArgList returns [pANTLR3_STRING s]
	: { $s = luagenSemanticActions_getNewString(); }
		(COMMA {$s->append8($s, ", ");}
		(rhs=argValue
			{
				$s->appendS($s, $rhs.s);
			}
		)?)
	;

triggerStmt
	:	^(TRIGGERSTMT INTEGER expr)
	|	^(TRIGGERSTMT ALL expr)
	;
	
/// EXPRESSIONS
binaryOp
	:	
		EQUAL
	|	NOTEQUAL
	|	GREATERTHAN
	|	GET
	|	LOWERTHAN
	|	LET
	|	PLUS
	|	MINUS
	|	MULT
	|	DIV
	|	MODULO
	|	LOGOR
	|	LOGXOR
	|	LOGAND
	|	BITOR
	|	BITXOR
	|	BITAND
	|	EXP	
	;

unaryOp
	:
	(	NOT
	|	MINUS
	|	BITNOT
	)
	;

interval returns [pANTLR3_STRING leftLim, pANTLR3_STRING rightLim, pANTLR3_STRING minVal, pANTLR3_STRING maxVal]
	:	
		^(INTERVAL (leftLimit=OP | leftLimit=OB) minValue=expr maxValue=expr (rightLimit=CP | rightLimit=CB))
		{
			$leftLim = $leftLimit.text;
			$rightLim = $rightLimit.text;
			$minVal = $minValue.s;
			$maxVal = $maxValue.s;
		}
	;

exprEqualityOp
	:	EQUAL | NOTEQUAL
	;

expr	returns [pANTLR3_STRING s, preeval_t p]
:
	{ $s = luagenSemanticActions_getNewString(); 
	  pe.s = NULL; }	
	(	(exprInterval) => exprInterval							{$s->appendS($s, $exprInterval.s); $p.isConstant = false;}
	|	(^(binaryOp expr expr))=>^(o=binaryOp e1=expr e2=expr)	{generateBinaryOp($s, $o.text->chars, $e1.s, $e2.s, &$p, $e1.p, $e2.p);}
	|	^(op2=unaryOp e3=expr)									{generateUnaryOp($s, $op2.text->chars, $e3.s); preevalUnary($op2.text->chars, &$e3.p); $p = $e3.p;}
	|	^(ASSIGN vr=varReference e4=expr)						{$s->append8($s, "Utils.assign(self:"); $s->appendS($s, $vr.dst); $s->append8($s, ", "); $s->appendS($s, $vr.idx); $s->append8($s, ", "); $s->appendS($s, $e4.s); $s->append8($s, ")"); $p.isConstant = false;}
	|	tc=triggerCall											{$s->append8($s, "(self"); $s->appendS($s, $tc.s); $s->append8($s, ")"); $p.isConstant = false;}
	|	^(TRIGGERREDIR npr=noparameterRedirections tc0=triggerCall)	{$s->append8($s, "(self:"); generateTriggerRedir($s, $npr.text, NULL, $tc0.s); $s->append8($s, ")"); $p.isConstant = false;}
	|	^(TRIGGERREDIR ^(pr=parameterRedirections pe=expr?)	tc1=triggerCall)  {$s->append8($s, "(self:"); generateTriggerRedir($s, $pr.text, $pe.s, $tc1.s); $s->append8($s, ")"); $p.isConstant = false; }
	|	number													{$s->appendS($s, $number.text); $p = $number.p;}
	)
	;

exprInterval returns [pANTLR3_STRING s]
	:
		{ $s = luagenSemanticActions_getNewString(); }
		^(op=exprEqualityOp lhs=expr in=interval)
		{
			generateIntervalOp($s, $op.text, $lhs.s, $in.leftLim, $in.rightLim, $in.minVal, $in.maxVal);		
		}
	;
//////////////////////////////

triggerCall returns [pANTLR3_STRING s]	
	:
	{ $s = luagenSemanticActions_getNewString(); }
	(	^(TRIGGERCALL tn=triggerRegularName tp=triggerParams)	{$s->append8($s, ":"); $s->append8($s, luagenSemanticActions_getNameForTrigger($tn.text)); $s->append8($s, "("); $s->appendS($s, $tp.s); $s->append8($s, ")");}
	|	^(TRIGGERCALL tn2=wSpaceSyntaxList id=ID)
		{
			pANTLR3_STRING buf = luagenSemanticActions_getNewString();
			regularizeWSpaceAttr(buf, $id.text);
			$s->append8($s, ":"); $s->append8($s, luagenSemanticActions_getNameForTrigger($tn2.text)); $s->append8($s, "()."); $s->appendS($s, buf);
		}
	|	oldStyleTriggerCall		{$s->append8($s, ":"); $s->appendS($s, $oldStyleTriggerCall.s);}
	|	varReference			{$s->append8($s, "."); $s->appendS($s, $varReference.s);}
	)
	;


equalityOp
	:	EQUAL | NOTEQUAL
	;
	
numberCompOp
	:	EQUAL | NOTEQUAL | GREATERTHAN | GET | LOWERTHAN | LET
	;
	
// Old-style triggers
oldStyleTriggerCall returns [pANTLR3_STRING s]
	:
	{ $s = luagenSemanticActions_getNewString(); }
	(
		^(TRIGGERCALL tName0=ANIMELEM in1=INTEGER
			{$s->append8($s, luagenSemanticActions_getNameForTrigger($tName0.text));
			 $s->append8($s, "(");
			 $s->appendS($s, $in1.text);
			} (
				{$s->append8($s, ", ");}
				(nc1=numberCompOp
				{appendNumberCompOp($s, $nc1.text);
				 $s->append8($s, ", ");
				}
				)? 
				si1=signedInteger
				{$s->appendS($s, $si1.s);}
			  )?
			)
		{
			$s->append8($s, ")");
		}
		| ^(TRIGGERCALL oldStyleWithString eq2=equalityOp str2=STRING_LITERAL)
		{
			// Special case: command()
			// Explanation:
			// In mugen, 'command' is not a trigger that returns a string. Instead when you do command="holdfwd"
			// it checks if holdfwd is among the active commands at that moment.
			// To achieve an equivalent behavior, self:command() == "holdfwd" must be translated to self:command("holdfwd")
			//
			if(!strcmp($oldStyleWithString.s->chars, "command()"))
			{
				s->append8(s, "command(");
				s->appendS(s, $str2.text);
				s->append8(s, ")");
				
				if(!strcmp($eq2.text->chars, "!="))
				{
					s->append8(s, " == 0");	// TODO: Replace this by (*not* self:command("cmdname"))
				}

			} else {
				// Anything else
				$s->appendS($s, $oldStyleWithString.s);
				appendEqualityOp($s, $eq2.text);
				$s->appendS($s, $str2.text);
			}
		}
		| ^(TRIGGERCALL oldStyleSelectorString sfx3=selectorStringSuffix)
		{
			$s->append8($s, luagenSemanticActions_getNameForTrigger($oldStyleSelectorString.text));
			$s->append8($s, "(\"");
			$s->appendS($s, $sfx3.text);
			$s->append8($s, "\")");
		}
		| ^(TRIGGERCALL tname3=HITDEFATTR						
						eo3=equalityOp 
						arg3_0=specialID
						{$s->append8($s, luagenSemanticActions_getNameForTrigger($tname3.text));
						 $s->append8($s, "(\"");
						 appendEqualityOp($s, $eo3.text);
						 $s->append8($s, "\", \"");
						 $s->appendS($s, $arg3_0.text);
						 $s->append8($s, "\"");
						}						
						(arg3_n=ID
						{$s->append8($s, ", \"");
						 $s->appendS($s, $arg3_n.text);
						 $s->append8($s, "\"");
						}
						)+)		
		| ^(TRIGGERCALL ^(osp4=oldStyleProj
						{$s->append8($s, luagenSemanticActions_getNameForTrigger($ops4.text));
						 $s->append8($s, "(");
						}
						(in4=INTEGER
						// Remove the last character
						{
						 $s->insert8($s, $s->len - 1, "ID");
						 $s->append8($s, "ID");
						 $s->append8($s, "(");
						 $s->appendS($s, $in4.text);
						 $s->append8($s, ", ");
						 }
						)?) ops4=oldStyleProjSuffix						
						 { $s->appendS($s, $ops4.s);
						   $s->append8($s, ")"); }
						)
		{
			$s->appendS($s, $oldStyleProj.text);			
			$s->append8($s, "(");
			$s->append8($s, ")");
			
		}
		| ^(TRIGGERCALL oldStyleWithId		
						eq5=equalityOp
						arg5=specialID)
		{
			$s->append8($s, luagenSemanticActions_getNameForTrigger($oldStyleWithId.text));
			$s->append8($s, "()");
			appendEqualityOp($s, $eq5.text);
			$s->append8($s, "\"");
			$s->appendS($s, $arg5.text);
			$s->append8($s, "\"");
		}
		| ^(TRIGGERCALL tMod=TIMEMOD
			{$s->append8($s, luagenSemanticActions_getNameForTrigger($tMod.text));
			 $s->append8($s, "(");
			 }
			(nco6=numberCompOp
			{$s->append8($s, "\"");
			 appendNumberCompOp($s, $nco6.text);
			 $s->append8($s, "\"");
			}
			)? si6=signedInteger si6_2=signedInteger)
		{			
			$s->appendS($s, $si6.s);
			$s->append8($s, ", ");
			$s->appendS($s, $si6_2.s);
			$s->append8($s, ")");			
		}
	)
	;

selectorStringSuffix
	:	idSel
	|	TYPE
	;
	
specialID
	:	(S|ID)
	;
	
oldStyleWithString returns [pANTLR3_STRING s]
	:	{ $s = luagenSemanticActions_getNewString(); }	
	(
		oss=AUTHORNAME | oss=COMMAND | oss=NAME | oss=PxNAME
	)	{ $s->append8($s, luagenSemanticActions_getNameForTrigger($oss.text)); $s->append8($s, "()"); }
	|	tName=STAGEVAR sel=idSel
		{ $s->append8($s, luagenSemanticActions_getNameForTrigger($tName.text)); $s->append8($s, "(\""); $s->appendS($s, $sel.text); $s->append8($s, "\")"); }
	;
	
oldStyleSelectorString
	:	CNST | GETHITVAR
	;
	
oldStyleProj
	:	PROJCONTACT | PROJGUARDED | PROJHIT
	;

oldStyleProjSuffix returns [pANTLR3_STRING s]
	:	{ $s = luagenSemanticActions_getNewString(); }
		in=INTEGER
		{
			$s->appendS($s, $in.text);			
		} (
			{$s->append8($s, ", ");}
			(nco=numberCompOp
				{appendNumberCompOp($s, $nco.text);
				 $s->append8($s, ", ");
				}
			)? 
			in2=INTEGER
			{$s->appendS($s, $in2.text);}
		)?
	;

oldStyleWithId
	:	(TEAMMODE | MOVETYPE | STATETYPE | P2STATETYPE | P2MOVETYPE)
	;
	
///////////////////////////////////

triggerParams returns [pANTLR3_STRING s]
scope
{
	int nArgs;
}
	:	{	$s = luagenSemanticActions_getNewString(); 
			$triggerParams::nArgs = 0;
		}
		(expr
		{
			if($triggerParams::nArgs > 0)
			{
				$s->append8($s, ", ");
			}
			$s->appendS($s, $expr.s);
			++ $triggerParams::nArgs;
		}
		)*
	;

triggerRegularName
	:	ID | PxRELATED | TIME | CNSTSCALE
	;
	
wSpaceSyntaxList	// These triggers can be called like Vel X, HitVel Y, ....
	:	VEL | POS | HITVEL | P2BODYDIST | P2DIST | PARENTDIST | ROOTDIST | SCREENPOS
	;

// KEYWORDS AND BASIC TYPES
noparameterRedirections
	:
		'PARENT' | 'ROOT' | 'PARTNER'	
	;
	
parameterRedirections
	:
	'HELPER' | 'TARGET' | 'ENEMY' | 'ENEMYNEAR' | 'PLAYERID'
	;
	
cntArgKeywords
	:	'NONE' | 'ADD' | 'ADDALPHA' | 'ADD1' | 'SUB' |		  
		'INTRO' | 'INVISIBLE' | 'ROUNDNOTOVER' | 'NOBARDISPLAY' | 'NOBG' | 'NOFG' | 'NOSTANDGUARD' | 'NOCROUCHGUARD' | 'NOAIRGUARD' |
		'NOAUTOTURN' | 'NOJUGGLECHECK' | 'NOKOSND' | 'NOKOSLOW' | 'NOSHADOW' | 'GLOBALNOSHADOW' | 'NOMUSIC' | 'NOWALK' | 'TIMERFREEZE' |
		'UNGUARDABLE' | 'FOOT' | 'MID' | 'HEAD' | 'P1' | 'P2' | 'FRONT' | 'BACK' | 'LEFT' | 'RIGHT' | 'SINE' | 'SQUARE' | 'SINESQUARE' | 'OFF' |
		'PLAYER' | 'NORMAL' | 'LIGHT' | 'MEDIUM' | 'HARD' | 'UP' | 'DIAGUP' | 'DODGE' | 'HIT' | 'MISS' |
		 'HIGH' | 'LOW' | 'TRIP'
	;

varReference returns [pANTLR3_STRING s, pANTLR3_STRING dst, pANTLR3_STRING idx]
	:
	{	$s = luagenSemanticActions_getNewString(); 
		$dst = luagenSemanticActions_getNewString(); 
		$idx = luagenSemanticActions_getNewString(); }
	(	^(VAR		e1=expr)		{ $s->append8($s, "var["); $s->appendS($s, $e1.s); $s->append8($s, "]"); $dst->set8($dst, "var"); $idx->setS($idx, $e1.s); }
	|	^(FVAR		e2=expr)		{ $s->append8($s, "fvar["); $s->appendS($s, $e2.s); $s->append8($s, "]"); $dst->set8($dst, "fvar"); $idx->setS($idx, $e2.s); }
	|	^(SYSVAR	e3=expr)		{ $s->append8($s, "sysvar["); $s->appendS($s, $e3.s); $s->append8($s, "]"); $dst->set8($dst, "sysvar"); $idx->setS($idx, $e3.s); }
	|	^(SYSFVAR	e4=expr)		{ $s->append8($s, "sysfvar["); $s->appendS($s, $e4.s); $s->append8($s, "]"); $dst->set8($dst, "sysfvar"); $idx->setS($idx, $e4.s); }
	)
	;

reservedKWAsLHS
	:	POS | VEL | FACEP2 | VALUE2 | FLAGx | PxRELATED | NAME | STATETYPE | MOVETYPE | PHYSICS | TIME | 'PLAYER' | 'ADD'
	;

signedInteger returns [pANTLR3_STRING s]
	: { $s = luagenSemanticActions_getNewString(); }
	(	^(MINUS i=INTEGER) {$s->append8($s, "-"); $s->appendS($s, $i.text);}
	|	i=INTEGER {$s->setS($s, $i.text);}
	)
	;

// Primary types

attr_string
	:	S
	|	ID
	;
	
idSel
	:	ID
	|	IDSELECTOR
	;

signedNumber returns [pANTLR3_STRING s]
	:	{ $s = luagenSemanticActions_getNewString(); }
	(
		^(MINUS ni=number) {$s->append8($s, "-"); $s->appendS($s, $ni.text);}
	|	i=number		   {$s->appendS($s, $i.text);}
	)
	;

number returns [preeval_t p]
	:	i=INTEGER
		{
			$p.valType = CDT_INT;
			$p.data.intVal = $i.text->toInt32($i.text);
			$p.isConstant = true;
		}
	|	f=FLOAT
		{						
			$p.valType = CDT_FLOAT;
			$p.data.floatVal = (float)atof($f.text->chars);
			$p.isConstant = true;
		}
	;

///////////////////////////////
// CMD

cmdDefBlock
	:	^(COMMAND
		{			
			pANTLR3_STRING s = luagenSemanticActions_getNewString();			
			char tmp[30];
			sprintf(tmp, "cmd_\%d", rand());						
			luagenSemanticActions_beginStateCodeBlock(CBT_COMMAND, tmp);			
			s->append8(s, "table.insert(");
			s->append8(s, luagenSemanticActions_getEntityName());
			s->append8(s, ".m_commands, {");
			luagenSemanticActions_appendCodeLine(s);			
			luagenSemanticActions_incInd();
		}
			cmdStmt+			
		{
			luagenSemanticActions_decInd();
			luagenSemanticActions_appendCodeLineC("})");
			luagenSemanticActions_endCodeBlock();
		}

		)	
		
	;
	
cmdStmt	
	:	cmdNameStmt | cmdDefStmt | cmdTimeStmt | cmdBufferTimeStmt
	;
		
cmdNameStmt
	:	^(NAME cmdName=STRING_LITERAL)
		{
			pANTLR3_STRING s = luagenSemanticActions_getNewString();
			s->append8(s, "name = ");
			s->appendS(s, $cmdName.text);
			s->append8(s, ", ");
			luagenSemanticActions_appendCodeLine(s);
		}
	;
	
cmdDefStmt
scope
{
	pANTLR3_STRING scmd;
}	:	{ $cmdDefStmt::scmd = luagenSemanticActions_getNewString(); }
		^(COMMAND (cs=cmdString
			{
				$cmdDefStmt::scmd->appendS($cmdDefStmt::scmd, $cs.s);
				$cmdDefStmt::scmd->append8($cmdDefStmt::scmd, ",");
			}
		)+)
		{
			pANTLR3_STRING s = luagenSemanticActions_getNewString();
			s->append8(s, "command = \"");
			$cmdDefStmt::scmd->chars[$cmdDefStmt::scmd->len - 1] = '\0';	// Remove the last comma
			
			s->appendS(s, $cmdDefStmt::scmd);
			s->append8(s, "\", ");
			luagenSemanticActions_appendCodeLine(s);		
		}
	;
		
cmdTimeStmt
	:	^(TIME cmdTime=INTEGER)
		{
			pANTLR3_STRING s = luagenSemanticActions_getNewString();
			s->append8(s, "time = ");
			s->appendS(s, $cmdTime.text);
			s->append8(s, ", ");
			luagenSemanticActions_appendCodeLine(s);
		}
	;
		
cmdString returns [pANTLR3_STRING s]
	:	{ $s = luagenSemanticActions_getNewString(); }
	(
		cmdStringUnit
		{$s->setS($s, $cmdStringUnit.s);
		}
	|	^(PLUS cmdS1=cmdString cmdS2=cmdString)
		{$s->appendS($s, $cmdS1.s);
		 $s->append8($s, "+");
		 $s->appendS($s, $cmdS2.s);
		}
	)
	;
	
cmdStringUnit returns [pANTLR3_STRING s]
	:	{ $s = luagenSemanticActions_getNewString(); }
	(
		^(CMDUNIT
			^(CMDMODIFIERS cmdStringPrefix			
			{
				$s->appendS($s, $cmdStringPrefix.s);
			}
			) 
			cb1=cmdButton
			{
				$s->appendS($s, $cb1.s);
			}
		)
	|	^(CMDUNIT cb2=cmdButton
			{
				$s->appendS($s, $cb2.s);
			}
		)
	)
	;
		
cmdButton returns [pANTLR3_STRING s]
	:	{ $s = luagenSemanticActions_getNewString(); }
		(F {$s->appendS($s, $F.text);} | S {$s->appendS($s, $S.text);} | ID {$s->appendS($s, $ID.text);})+
	;
	
cmdStringPrefix returns [pANTLR3_STRING s]
	:	{ $s = luagenSemanticActions_getNewString(); }
		(cmdStringPrefixUnit
		{
			$s->appendS($s, $cmdStringPrefixUnit.text);
		}
		)+
	;
cmdStringPrefixUnit
	:
		(DIV | BITNOT | DOLLAR | PLUS | GREATERTHAN | INTEGER)
	;
	
cmdBufferTimeStmt
	:	^('BUFFER.TIME' bufTime=INTEGER)
		{
			pANTLR3_STRING s = luagenSemanticActions_getNewString();
			s->append8(s, "buffer_time = ");
			s->appendS(s, $bufTime.text);
			s->append8(s, ", ");
			luagenSemanticActions_appendCodeLine(s);
		}
	;

// Button remapping
remapBlock
	:	^(REMAP	
		{
			// Cloudi.m_buttonsRemap = {
			//	["x"] = "x"
			// }
			pANTLR3_STRING s = luagenSemanticActions_getNewString();
			luagenSemanticActions_beginStateCodeBlock(CBT_BUTTONSREMAP, "buttonsRemap");
			s->append8(s, luagenSemanticActions_getEntityName());
			s->append8(s, ".m_buttonsRemap = {");
			luagenSemanticActions_appendCodeLine(s);			
			luagenSemanticActions_incInd();

		}
		remapStmt*
		{
			luagenSemanticActions_decInd();
			luagenSemanticActions_appendCodeLineC("}");			
		}
		)
	;
	
remapStmt
scope
{
	pANTLR3_STRING tmp;
}	:	{ $remapStmt::tmp = luagenSemanticActions_getNewString(); }

		^(ASSIGNSTMT 		
		src=remapTarget
		{
		
			$remapStmt::tmp->append8($remapStmt::tmp, "[\"");
			$remapStmt::tmp->appendS($remapStmt::tmp, $src.text);
			$remapStmt::tmp->append8($remapStmt::tmp, "\"] = \"");
		}
		(dst=remapTarget
			{
				$remapStmt::tmp->appendS($remapStmt::tmp, $dst.text);
			}
		)?
		{
			$remapStmt::tmp->append8($remapStmt::tmp, "\"");
			//if(LA(1) == ASSIGNSTMT)
			//{
				$remapStmt::tmp->append8($remapStmt::tmp, ",");
			//}
			luagenSemanticActions_appendCodeLine($remapStmt::tmp);
		}
		)
	;
	
remapTarget
	:	(ID | S)
	;

// Defaults block
defaultsBlock
	:	
		{
			pANTLR3_STRING s = luagenSemanticActions_getNewString();
			luagenSemanticActions_beginStateCodeBlock(CBT_INFO, "cmdDefaults");
			s->append8(s, luagenSemanticActions_getEntityName());
			s->append8(s, ".m_cmdDefaults = {");
			luagenSemanticActions_appendCodeLine(s);
			luagenSemanticActions_incInd();

		}
		^(DEFAULTS 
		defaultsStmt*
		)
		
		{
			luagenSemanticActions_decInd();
			luagenSemanticActions_appendCodeLineC("}");
		}
	;
	
defaultsStmt
	:	^(ASSIGNSTMT 
			idSel 
			i=INTEGER
			{
				pANTLR3_STRING s = luagenSemanticActions_getNewString();
				s->append8(s, "[\"");
				s->appendS(s, $idSel.text);
				s->append8(s, "\"]");
				s->append8(s, " = ");
				s->appendS(s, $i.text);				
				s->append8(s, ",");
				luagenSemanticActions_appendCodeLine(s);
			}
			)
	;
