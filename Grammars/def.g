grammar def;

options
{
    output=AST;
    k=2;
    memoize=true;
   // ASTLabelType= CommonTree; // type of $stat.tree ref etc...
    language=C;
    backtrack=false;
}

tokens
{
	COLLISIONBOX;
	NODEFAULT;
	ANIMELEM;
	ASSIGNSTMT;
	GROUP;
	GROUPNAME;
}

ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_'|'.')*
    ;

INT	:	'-'? '0'..'9'+
	;

FLOAT
    :   '-'? ('0'..'9')+ '.' ('0'..'9')*
    |   '-'? '.' ('0'..'9')+
    ;

COMMENT
    :   ';' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    ;

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;

STRING_LITERAL
    :  '"' ~('\\'|'"')* '"'
    ;


def	:	infoBlock+
	;


infoBlock
	:	'[' groupName ']' 
		infoStmt+ 		-> ^(GROUP groupName infoStmt+)
	;

groupName
	:	ID+ -> ^(GROUPNAME ID+)
	;

infoStmt:	lhs=ID '=' rhs=infoStmtRHS -> ^(ASSIGNSTMT $lhs $rhs)
	;

number	:	INT | FLOAT
	;

infoStmtRHS
	:	(STRING_LITERAL | numList | ID)
	;
	
numList	:	number (','! number)*
	;
/*
intDots	:	INT ('.' INT)+
	;
*/	
/////////////////////////
// .air format
/////////////////////////

air	:	actionBlock+
	;

actionBlock
	:	'['! 'BEGIN'! 'ACTION'^ INT ']'!
		actionStmt+
	;

loop	:	'LOOPSTART'^
	;

actionStmt
	:	loop? (clsnBlock | frameStmt)
	;
	
	
clsnBlock
	:	('CLSN1' |
		 'CLSN1DEFAULT' |
		 'CLSN2' |
		 'CLSN2DEFAULT')^ ':'! INT
		clsnDefStmt*
	;
clsnDefStmt
	:	('CLSN1' | 'CLSN2')! '['! INT^ ']'! '='! INT ','! INT ','! INT ','! INT
	;

frameStmt
	:	group=INT ',' image=INT ',' x=INT ',' y=INT ',' len=INT opts=moreFrameStmt? -> ^(ANIMELEM $group $image $x $y $len $opts?)
	;
	
moreFrameStmt
	:	','! frameArgs1? (','! frameArgs2)?
	;

frameArgs1
	:	('H'|'V'|'HV'|'VH')
	;

frameArgs2
	:	'A' | 'A1' | 'S' | 'AS' INT 'D' INT
	;
