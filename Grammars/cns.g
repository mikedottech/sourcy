//////////////////////////////////////////
//										//
// LEXER + PARSER Grammar for M.U.G.E.N //
// cns / cmd format						//
//										//
// 2011 - Miguel Angel Exposito			//
// <radexx[at]gmail.com>				//
//////////////////////////////////////////

grammar cns;


options {
    output=AST;
    k=3;
    memoize=true;
    language=C;
    backtrack=false;
}


// These are imaginary tokens that will serve as parent nodes
// for grouping other tokens in our AST.
tokens {
	TRIGGERSTMT;
	ALL;
	INTERVAL;
	TRIGGERCALL;
	TRIGGERREDIR;
	EXPRREDIR;
	ASSIGNSTMT;
	CNTNAME;
	CNS;
	INFOBLOCK;
	STATECNTID;
	CMDMODIFIERS;
	CMDUNIT;	
}


@lexer::header {
#	define	ANTLR3_INLINE_INPUT_UTF8	// For japanese and other foreign languages victory strings
#	include "antlr3customtokenstream.h"
}

@parser::header {

#	include "CNSGrammarInclude.h"
#	include "CNSSemanticActions.h"
#	include "CNSControllerUsage.h"
#	include "antlr3customtokenstream.h"

#	define DISABLECH() ((pANTLR3_CUSTOM_TOKEN_STREAM)INPUT->super)->swChannelState ++;
#	define ENABLECH() \
((pANTLR3_CUSTOM_TOKEN_STREAM)INPUT->super)->swChannelState --;
//while(((pANTLR3_COMMON_TOKEN) ((pANTLR3_CUSTOM_TOKEN_STREAM)INPUT->super)->tokens->elements[((pANTLR3_CUSTOM_TOKEN_STREAM)INPUT->super)->p + 2].element)->type != NEWLINE) ((pANTLR3_CUSTOM_TOKEN_STREAM)(INPUT->super))->p--;


}

@parser::members {

	// Returns 'S' or 'F' if the expression is redirected
	//  For example: SIFELSE, FIFELSE, ...
	// otherwise returns 0
	//  example: SCREENPOS  or  FRONTEDGELIST
	char disambiguateSF(pANTLR3_COMMON_TOKEN t)
	{
		int i;
		pANTLR3_STRING s = t->getText(t);		

		char first = toupper((char)s->chars[0]);

		if(first == 'S' || first == 'F')
		{	
			if(cnsActions_triggerExist((const char*)(s->chars + 1)))
			{
				return first;				
			}
			return 0;
		} else {
			return 0;
		}
	}
		
	void fixTriggerCall(pANTLR3_BASE_TREE t)
	{
		int i;
		pANTLR3_BASE_TREE t2 = (pANTLR3_BASE_TREE)t->getChild(t, 0); // TRIGGERCALL
		pANTLR3_COMMON_TOKEN tk = (pANTLR3_COMMON_TOKEN) t2->getToken(t2);
		pANTLR3_STRING s = t2->getText(t2);
		
		//printf(">>>> \%s\n", s->chars);
	/*
		// Cut the first character from the token
		for(i=0;i<s->size; ++i)
		{
			s->chars[i] = s->chars[i+1];
		}
		--s->size;
	*/
		
		//printf("NEW STRING: \%s\n", s->chars);
		//system("pause");		
	}

}

//------------------------------------
// LEXER RULES
//------------------------------------

OB		:	'[';
CB		:	']';
COMMA	:	',';
TRIGGER	:	'TRIGGER';
TRIGGERALL
		:	'TRIGGERALL';
OP		:	'(';
CP		:	')';
PLUS	:	'+';
MINUS	:	'-';
EQUAL	:	'=';
MULT	:	'*';
DIV		:	'/';
MODULO	:	'%';
EXP		:	'**';
NOT		:	'!';
LOGAND	:	'&&';
LOGOR	:	'||';
LOGXOR	:	'^^';
BITNOT	:	'~';
BITAND	:	'&';
BITOR	:	'|';
BITXOR	:	'^';
ASSIGN	:	':=';
NOTEQUAL:	'!=';
LOWERTHAN	:	'<';
GREATERTHAN	:	'>';
LET		:	'<=';
GET		:	'>=';
DOT		:	'.';

DOLLAR	:	'$';

STATE	:	'STATE';
STATEDEF:	'STATEDEF';

// State controller parameters
// TYPE
//PERSISTENT
//	:	'PERSISTENT';

//IGNOREHITPAUSE
//	:	'IGNOREHITPAUSE';

// Whitespace syntax triggers
VEL		:	'VEL';
POS		:	'POS';
HITVEL	:	'HITVEL';
P2BODYDIST
		:	'P2BODYDIST';
P2DIST	:	'P2DIST';
PARENTDIST
		:	'PARENTDIST';
ROOTDIST:	'ROOTDIST';
SCREENPOS
		:	'SCREENPOS';
	

// Trigger followed by int syntax triggers
PROJCONTACT
		:	'PROJCONTACT';
PROJGUARDED
		:	'PROJGUARDED';	
PROJHIT	:	'PROJHIT';

// Old-style triggers
ANIMELEM:	'ANIMELEM';
AUTHORNAME
		:	'AUTHORNAME';
COMMAND	:	'COMMAND';
CNSTSCALE
		:	'CONST' ('240' | '480' | '720') 'P';
CNST	:	'CONST';
GETHITVAR
		:	'GETHITVAR';
HITDEFATTR
		:	'HITDEFATTR';
NAME	:	'NAME';
PxNAME	:	'P' '1'..'4' 'NAME';
STAGEVAR:	'STAGEVAR';
TIMEMOD	:	'TIMEMOD';
VAR		:	'VAR';		// They're also triggers!
FVAR	:	'FVAR';		// They're also triggers!
SYSVAR	:	'SYSVAR';	// They're also triggers!
SYSFVAR	:	'SYSFVAR';	// They're also triggers!
MOVETYPE:	'MOVETYPE';
TYPE	:	'TYPE';
HITFLAG :	'HITFLAG';

STATETYPE
	:	'STATETYPE';
PHYSICS	:	'PHYSICS';


// Other special names


P2STATETYPE:	'P2STATETYPE';

TEAMMODE:	'TEAMMODE';
TIME	:	'TIME';
REMAP	:	'REMAP';
DEFAULTS:	'DEFAULTS';

// Tokens that can go as lhs in assignments and mix letters and numbers
FACEP2	:	'FACEP2';
VALUE2	:	'VALUE2';

FLAGx	:	'FLAG' ('2'|'3')?;

PxRELATED
	:	'P' '1'..'2' ('SPRPRIORITY' | 'FACING' | 'GETP2FACING' | 'STATENO' | 'GETP1STATE' | 'DEFMUL' | 'LIFE')?;

P2MOVETYPE
	:	'P2MOVETYPE'
	;

// Tokens that can go as rhs in assignments and mix letters and numbers
// ...

S : 'S';
F : 'F';

// Generic trigger names and others
ID	:	LETTER+;
IDSELECTOR
	:	(LETTER | DOT)+;

STRING_LITERAL: '"' (options { greedy = false; }:(NONCONTROL_CHAR)*) '"';

fragment NONCONTROL_CHAR: LETTER | DIGIT | SYMBOL | SPACE;
fragment LETTER: 	LOWER | UPPER | SPECIAL;
fragment LOWER: 	'a'..'z';
fragment UPPER: 	'A'..'Z';
fragment DIGIT: 	'0'..'9';
fragment SPACE: 	' ' | '\t';
fragment SPECIAL:	'_';

// Note that SYMBOL omits the double-quote character,
// digits, uppercase letters and lowercase letters.
fragment SYMBOL: 	'!' | '#'..'/' | ':'..'@' | '['..'`' | '{'..'~';

fragment COMMENT options { greedy = false; }: ';' (~('\r' | '\n'))*;

NEWLINE :	(COMMENT? '\r'? '\n') { $channel = ANTLR3_TOKEN_SWITCHABLE_CHANNEL;};


FLOAT   :		'0'..'9'* '.' '0'..'9'+;
INTEGER : 		'0'..'9'+;
	
QM		:		'?' | '*' | '#' | ':' ; // Just for state controller names

WHITESPACE:		(' ' | '\t')+ { $channel = HIDDEN; };

//------------------------------------
// PARSER RULES
//------------------------------------

cns	:	cr? (state | infoBlock | cmdDefBlock | remapBlock | defaultsBlock)+ EOF!;

cr	: NEWLINE!+
	;

infoBlock:	OB name=idSel CB cr
			infoStmt+ -> ^(INFOBLOCK $name infoStmt+)
	;

infoStmt:	(lhs0=idSel | lhs1=reservedKWAsLHS | lhs2=victoryLHS) EQUAL (rhs0=infoRHS | rhs1=STRING_LITERAL) cr -> ^(ASSIGNSTMT $lhs0? $lhs1? $lhs2? $rhs0? $rhs1?)
		
	;
	
victoryLHS
	:	'VICTORY'^ INTEGER
	;
	
	
infoRHS	:	signedNumber (COMMA! signedNumber)*;


state
@init
{
	cnsActions_setState();
}	:
	OB! STATEDEF^ signedInteger CB! cr		
		((stateAssignStmt)=>stateAssignStmt | assignStmt)*
		stateCntBlock*
	;


attr_string
	:	S | ID
	;

stateAssignStmt
	:	(TYPE^ EQUAL! attr_string cr |
		PHYSICS^ EQUAL! attr_string cr |
		MOVETYPE^ EQUAL! attr_string cr )
	;

testTriggers
	:	triggerStmt+
	;

testControllers
	:
		stateCntStmts	
	;

stateCntBlock
scope {
  	cnsControllerUsage_t *pControllerUsage;
}
@init {
	$stateCntBlock::pControllerUsage = malloc(sizeof(cnsControllerUsage_t));
	$stateCntBlock::pControllerUsage->pSignature = NULL;
	$stateCntBlock::pControllerUsage->usedSyntax = -1;
	cnsActions_setController();
}
	:	OB! STATE^ stateCntNamePre CB! cr
		stateCntType		
		stateCntStmts
		// Attach to the STATE node the userdata
		{
			root_0->u = (void*)$stateCntBlock::pControllerUsage;
		}
	;

stateCntType
	:
		TYPE^ EQUAL! (tName=ID | tName='HELPER' | tName='CHANGEANIM2') cr	// Special types (have numbers or are keywords)
		// Find the current trigger type in the DB
		{cnsActions_getControllerSignature((const char*)$tName.text->chars, $stateCntBlock::pControllerUsage)}?
	;

stateCntNamePre		// Workaround for ANTLR3
	:	stateCntName -> ^(STATECNTID stateCntName)
	;

stateCntName
	:	// Best solution
	{
		while(LA(1) != CB)
		{
			CONSUME();
			PERRORRECOVERY=ANTLR3_FALSE;
            FAILEDFLAG=ANTLR3_FALSE;
		} 
	}
	;
		
stateCntStmts
	:	((triggerStmt | assignStmt | scAssignStmt))+
	;

triggerStmt
	:	TRIGGER i=INTEGER EQUAL {DISABLECH()} e=expr {ENABLECH()} cr? -> ^(TRIGGERSTMT $i $e)
	|	TRIGGERALL EQUAL {DISABLECH()} e=expr {ENABLECH()} cr?  -> ^(TRIGGERSTMT ALL $e)
	;

scAssignStmt
	:	HITFLAG EQUAL id=ID (mod=PLUS|mod=MINUS)? cr -> ^(ASSIGNSTMT HITFLAG $id $mod)
	;
	
assignStmt
scope
{
	int currentArg;
}	
@init
{
	$assignStmt::currentArg = 0;
}
	:
	(		lhs0=idSel				{cnsActions_setLHS($lhs0.str->chars)}?
		|	lhs1=reservedKWAsLHS	{cnsActions_setLHS($lhs1.str->chars)}?
		|	lhs2=varReference		{cnsActions_setLHS($lhs2.str->chars)}?
		 ) EQUAL (
		 rhs0=argValueList 
		 )? cr -> ^(ASSIGNSTMT $lhs0? $lhs1? $lhs2? $rhs0?)
	;
		
argValueList 
	:	firstArgValue moreArgValues*
	|	moreArgValues+ 
	;

firstArgValue
	:	
	((S|F) expr) => (red=S | red=F) ex=expr -> ^(EXPRREDIR $red $ex)
	| {LA(1) == ID && disambiguateSF(LT(1)) == 'S'}? => ex2=expr {fixTriggerCall($ex2.tree);} -> ^(EXPRREDIR S $ex2)
	| {LA(1) == ID && disambiguateSF(LT(1)) == 'F'}? => ex2=expr {fixTriggerCall($ex2.tree);} -> ^(EXPRREDIR F $ex2)
	| argValueAtom
	| S
	| F
	;
	
moreArgValues
	:	(COMMA {++$assignStmt::currentArg;} argValueAtom)
	;
	
argValueAtom
	:	
	{cnsActions_disambiguateTriggerID($assignStmt::currentArg)}?=> (ID) => id=ID -> $id				// Disambiguate ID strings as triggers
	| (expr | STRING_LITERAL | cntArgKeywords)	
	;
	
reservedKWAsLHS returns [pANTLR3_STRING str]
	:	(s=POS | s=VEL | s=FACEP2 | s=VALUE2 | s=FLAGx | s=PxRELATED | s=NAME | s=STATETYPE | s=MOVETYPE | s=PHYSICS | s=TIME | s='PLAYER' | s='ADD' /*| s='HELPERTYPE'*/)
		{$str = $s.text;}
	;

cntArgKeywords
	:	trans_type | flag_name | postype | postype_string | wave_type | helpertype_string | anim_type | hit_type | attack_type
	;
 
trans_type: 'NONE' | 'ADD' | 'ADDALPHA' | 'ADD1' | 'SUB'
		  ;
		  
flag_name: 'INTRO' | 'INVISIBLE' | 'ROUNDNOTOVER' | 'NOBARDISPLAY' | 'NOBG' | 'NOFG' | 'NOSTANDGUARD' | 'NOCROUCHGUARD' | 'NOAIRGUARD' |
			'NOAUTOTURN' | 'NOJUGGLECHECK' | 'NOKOSND' | 'NOKOSLOW' | 'NOSHADOW' | 'GLOBALNOSHADOW' | 'NOMUSIC' | 'NOWALK' | 'TIMERFREEZE' |
			'UNGUARDABLE'
			;
			
postype:	'FOOT' | 'MID' | 'HEAD'
			;
			
postype_string: 'P1' | 'P2' | 'FRONT' | 'BACK' | 'LEFT' | 'RIGHT'
				;

wave_type:	'SINE' | 'SQUARE' | 'SINESQUARE' | 'OFF'
			;
			
helpertype_string: 'PLAYER' | 'NORMAL'
			;
anim_type:	'LIGHT' | 'MEDIUM' | 'HARD' /*| 'BACK' */| 'UP' | 'DIAGUP'	
			;

hit_type:	'DODGE' | 'HIT' | 'MISS'
			;

attack_type: 'HIGH' | 'LOW' | 'TRIP'
			;

expr
	:	conditionalORExp
	;

parExp
	:	OP! expr CP!
	;
	
expList	:	expr? (moreExpList)=>moreExpList
	;

moreExpList
	:	(COMMA! expr)*;

// Expression types by ascending order of operator precedence

conditionalORExp // a || b
	:	e1=conditionalXORExp ( LOGOR^ e2=conditionalXORExp )*
	;
conditionalXORExp	// a ^^ b
	:	e1=conditionalANDExp ( LOGXOR^ e2=conditionalANDExp )*
	;
conditionalANDExp	// a && b
	:	e1=bitORExp ( LOGAND^ e2=bitORExp )*
	;
bitORExp	// a | b	
	:	e1=bitXORExp ( BITOR^ e2=bitXORExp )*
	;
	
bitXORExp	// a ^ b
	:	e1=bitANDExp ( BITXOR^ e2=bitANDExp )*
	;
	
bitANDExp	// a & b
	:	e1=assignExp ( BITAND^ e2=assignExp )*
	;
	
assignExp	// var(num) := b , fvar(num) := b
	:	(varReference ASSIGN)=>varAssignment 
	|	equalityExp
	;

varAssignment
	:	v=varReference ASSIGN^ e1=equalityExp		
	;

equalityOp
	:	EQUAL | NOTEQUAL;
	
equalityExp		// a = b, a != b, a = [0,3]
	:	
		e1=relationalExp (equalityOp^ ((interval)=>interval | relationalExp))*
	;
	
relationalExp	// a > b. a >= b, a < b, a <= b
	:	e1=addSubExp (relationalOp^ addSubExp )*
	;
		
relationalOp
	:	GREATERTHAN | GET | LOWERTHAN | LET
	;

numberCompOp
	:	equalityOp | relationalOp
	;
	
addSubOp
	:	PLUS | MINUS
	;
addSubExp	// a + b, a - b
	:	e1=multDivModExp ( addSubOp^ e2=multDivModExp )*
	;
	
	
multDivModExp	// a * b, a / b, a % b
	:	e1=expExp ( multDivModOp^ e2=expExp )*
	;
	
multDivModOp
	:	MULT | DIV | MODULO
	;
expExp
	:		// a ** b
		e1=unaryExp ( EXP^ e2=unaryExp )*
	;
		
unaryExp :		// !a, -a, ~a
		NOT^ e1=unaryExp
	|	MINUS^ e2=unaryExp
	|	BITNOT^ e3=unaryExp 
	|	primaryExp
	;

//catch[FailedPredicateException e] {
//	reportError("Type mismatch");
//}

primaryExp 	// (a), Cos(a), 10, 10.3
	:	parExp 
	|	triggerCall
	|	triggerRedirection
	| 	number
/*	|	varReference */
	;
		
number	
	:	INTEGER 
	|	FLOAT
	;

signedInteger
	:	MINUS^? INTEGER
	;

triggerCall	// Cos(a)
	:	(name=ID | name=CNSTSCALE | name=PxRELATED | name=TIME) (args=arguments)? -> ^(TRIGGERCALL $name $args?)
	 	| wSpaceSyntax
	 	| oldStyleTriggerCall
	 	| varReference
	;
	
wSpaceSyntax		// These triggers can be called like Vel X, HitVel Y, ....
	:	name=wSpaceSyntaxList arg=ID -> ^(TRIGGERCALL $name $arg)
	;

wSpaceSyntaxList	// These triggers can be called like Vel X, HitVel Y, ....
	:	VEL | POS | HITVEL | P2BODYDIST | P2DIST | PARENTDIST | ROOTDIST | SCREENPOS
	;
	
arguments		// (expr, expr, expr)
	:	OP! expList CP!
	;	
	
interval:	// [0,3], (2,2), [2,6)...
		(open=OP | open=OB) a=expr COMMA b=expr (close=CP | close=CB) -> ^(INTERVAL $open $a $b $close)
	;
			// var(num) / fvar(num)

varReference returns [pANTLR3_STRING str]
	:	(vt=VAR^ | vt=FVAR^ | vt=SYSVAR^ | vt=SYSFVAR^) OP! expr CP! {$str = $vt.text;}
	;


triggerRedirection
	@init {
	}:	target0=parameterRedirections COMMA trig0=triggerCall  -> ^(TRIGGERREDIR $target0 $trig0)
	|	target1=noparameterRedirections COMMA trig1=triggerCall  -> ^(TRIGGERREDIR $target1 $trig1)
	;
		
noparameterRedirections
	:	'PARENT' | 'ROOT' | 'PARTNER'	
	;
	
parameterRedirections
	:	('HELPER' | 'TARGET' | 'ENEMY' | 'ENEMYNEAR' | 'PLAYERID')^ (OP! expr CP!)?
	;

// Old-style triggers
oldStyleTriggerCall
	:	ANIMELEM args0=animElemSuffix 					-> ^(TRIGGERCALL ANIMELEM $args0)
	|	name1=oldStyleWithString op1=equalityOp str1=STRING_LITERAL 	-> ^(TRIGGERCALL $name1 $op1 $str1)
	|	name2=oldStyleSelectorString args2=selectorStringSuffix 	-> ^(TRIGGERCALL $name2 $args2)
	|	HITDEFATTR args3=hitDefAttrSuffix 				-> ^(TRIGGERCALL HITDEFATTR $args3)
	|	name4=oldStyleProj (id4=INTEGER)? args4=oldStyleProjSuffix 	-> ^(TRIGGERCALL ^($name4 $id4?) $args4)
	|	name6=oldStyleWithId 	op6=equalityOp (args6=S|args6=ID)	-> ^(TRIGGERCALL $name6 $op6 $args6)
	|	TIMEMOD args8=timemodSuffix					-> ^(TRIGGERCALL TIMEMOD $args8)
	;
	
oldStyleWithId
	:	TEAMMODE | MOVETYPE | STATETYPE | P2STATETYPE | P2MOVETYPE
	;
	
oldStyleSelectorString
	:	CNST | GETHITVAR
	;

oldStyleWithString
	:	AUTHORNAME | COMMAND | NAME | PxNAME | STAGEVAR OP! idSel CP!
	;

oldStyleProj
	:	PROJCONTACT | PROJGUARDED | PROJHIT
	;
	
oldStyleProjSuffix
	:	(EQUAL INTEGER COMMA numberCompOp INTEGER) => EQUAL! INTEGER COMMA! numberCompOp INTEGER
	|	(EQUAL INTEGER COMMA INTEGER) => EQUAL! INTEGER COMMA! INTEGER
	|	EQUAL! INTEGER
	;
	
animElemSuffix
	:	(EQUAL INTEGER COMMA numberCompOp signedInteger) => EQUAL! INTEGER COMMA! numberCompOp signedInteger	// WARNING: For example: VELSET = ANIMELEM = 2, 3 is ambiguous! (3 can be the Y velocity component or the second optional argument of ANIMELEM)
	|	(EQUAL INTEGER COMMA signedInteger) => EQUAL! INTEGER COMMA! signedInteger
	|	EQUAL! INTEGER
	;
	
hitDefAttrSuffix
	:	equalityOp (S|ID) (COMMA! ID)+
	;
	
selectorStringSuffix
	:	OP! (idSel | TYPE) CP!
	;

timemodSuffix
	:
		numberCompOp? signedInteger COMMA! signedInteger
	;
/////////////////////////////////////////////////////////////////
compWithNumberOrInterval	// unused
	:	equalityOp interval | relationalOp number
	;
	
idSel returns [pANTLR3_STRING str]
	:	(s=ID
	|	 s=IDSELECTOR)
			{$str = $s.text;}
	;
	
signedNumber: MINUS^? number
	;
	
////////////////////////////////////
// Command definitions (.cmd files)
cmdDefBlock
	:	OB! COMMAND^ CB! cr
		cmdStmt+
	;
		
cmdStmt	
	:	cmdNameStmt | cmdDefStmt | cmdTimeStmt | cmdBufferTimeStmt
	;
		
cmdNameStmt
	:	NAME^ EQUAL! STRING_LITERAL cr
	;
	
cmdDefStmt
	:	COMMAND^ EQUAL! cmdString (COMMA! cmdString)* cr
	;
		
cmdTimeStmt
	:	TIME^ EQUAL! INTEGER cr
	;
		
cmdString
	:	cmdStringUnit (PLUS^ cmdStringUnit)*
	;
	
cmdStringUnit
	:	mods=cmdStringPrefix btns=cmdButton -> ^(CMDUNIT ^(CMDMODIFIERS $mods) $btns)
	|	cmdButton -> ^(CMDUNIT cmdButton)
	;
		
cmdButton
	:	(F | S | ID)+
	;
	
cmdStringPrefix
	:	(DIV | BITNOT | DOLLAR | PLUS | GREATERTHAN | INTEGER)+ 
	;
	
cmdBufferTimeStmt
	:	'BUFFER.TIME'^ EQUAL! INTEGER cr
	;

// Button remapping (.cmd files)
remapBlock
	:	OB! REMAP^ CB! cr
		remapStmt*
	;
	
remapStmt
	:	lhs=remapTarget EQUAL rhs=remapTarget? cr -> ^(ASSIGNSTMT $lhs $rhs?) 
	;
remapTarget
	:	(ID | S)
	;

// Defaults block
defaultsBlock
	:	OB! DEFAULTS^ CB! cr
		defaultsStmt*
	;
	
defaultsStmt
	:	lhs=idSel EQUAL rhs=INTEGER cr -> ^(ASSIGNSTMT $lhs $rhs)
	;
