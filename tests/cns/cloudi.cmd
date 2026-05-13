
; If new_button is left blank, the button cannot be pressed.
[Remap]
x = x
y = y
z = z
b = b
s = s

;-| Default Values |-------------------------------------------------------
[Defaults]
; Default value for the "time" parameter of a Command. Minimum 1




[command]
name = "ougi1"
command = F,B,D,F,x
time = 30


[command]
name = "ougi2"
command = D,F,x
time = 30

[command]
name = "ougi3"
command = D,F,U,x
time = 30

;-----------------

[command]
name = "ougi4"
command = B,F,B,y
time = 30

[command]
name = "ougi5"
command = F,B,D,y
time = 30

[command]
name = "ougi6"
command = D,B,F,y
time = 30

;-----------------

[command]
name = "ougi7"
command = F,D,B,y+x
time = 30

[command]
name = "ougi8"
command = D,D,B,y+x
time = 30


 ;-----------AI TEST INPUT

[Command]
name = "AI_ATK_Back"
command = D,F,B,U,B,U,a+b+c+x+y+z+b
time = 1

[Command]
name = "AI_ATK_Down"
command = D,F,B,U,U,a+b+a+b+x+y+z
time = 1

[Command]
name = "AI_ATK_Up"
command = D,F,B,U,a+b+c+x+y+z+b+c+x+y+z
time = 1

[Command]
name = "AI_ATK_Foward"
command = D,D,B,U,x+y+z+b+c+x+y+z
time = 1

[Command]
name = "AI_ATK_Down0"
command = D,F,B,U,U,a+b+c+x+y+z+b
time = 1

[Command]
name = "AI_ATK_Up0"
command = D,F,B,U,U,a+b+c+x+y+z+b+c+x+y+z
time = 1

[Command]
name = "AI_ATK_Foward0"
command = D,D,B,U+z+b+c+x+y+z
time = 1

[Command]
name = "AI_ATK_Run"
command = D,D,B,B,U,x+y+y+z+b+c+x+y+z
time = 1

[Command]
name = "AI_SP_Down"
command = D,D,B,U,x+y+y+c+x+y+z
time = 1

[Command]
name = "AI_SP_Up"
command = D,D,B,U,x+y+y+c+x+y+z+y+z+y+z
time = 1

[Command]
name = "AI_SP_Foward"
command = D,D,B,U,x+y+y+c+x+y+z+y+y+y+y
time = 1

[Command]
name = "AI_SP_Back"
command = D,U,U,x+y+c
time = 1

[Command]
name = "AI_SP_Back0"
command = D,U,U,x+y+c+x+y
time = 1

[Command]
name = "AI_SP_Up0"
command = D,D,B,U,B,x+y+y+c+c
time = 1

[Command]
name = "AI_SP_Down0"
command = D,D,B,B,x+y+y+c+c+c
time = 1


[Command]
name = "AI_OUGI1"
command = D,U,U,x+y+x+z+b+c+x+y+z
time = 1

[Command]
name = "AI_OUGI2"
command = D,D,D,x+y+z+z+b+c+x+y+z
time = 1

[Command]
name = "AI_OUGI3"
command = D,U,x+y+x+z+x+y+z
time = 1

[Command]
name = "AI_OUGI4"
command = D,D,D,x+y+z+x+y+z
time = 1

[Command]
name = "AI_OUGI5"
command = U,U,x+y+x+z+b+c
time = 1

[Command]
name = "AI_OUGI6"
command = D,D,x+y+z+z+z
time = 1

 [Command]
name = "AI_OUGI7"
command = D,D,x+y+z+z+z+z+z
time = 1

 [Command]
name = "AI_OUGI8"
command = D,D,x+y+z+z+z+z+y+z
time = 1

;-| Super Motions |--------------------------------------------------------

;-| Special Motions |------------------------------------------------------

;-| Double Tap |-----------------------------------------------------------
[Command]
name = "FF"     ;Required (do not remove)
command = F, F
time = 10

[Command]
name = "BB"     ;Required (do not remove)
command = B, B
time = 10

;-| 2/3 Button Combination |-----------------------------------------------
[Command]
name = "recovery" ;Required (do not remove)
command = x+y
time = 1

[Command]
name = "recovery"
command = y+z
time = 1

[Command]
name = "recovery"
command = x+z
time = 1

[Command]
name = "recovery"
command = a+b
time = 1

[Command]
name = "recovery"
command = b+c
time = 1

[Command]
name = "recovery"
command = a+c
time = 1

;-| Dir + Button |---------------------------------------------------------
[Command]
name = "back_x"
command = /$B,x
time = 1

[Command]
name = "back_y"
command = /$B,y
time = 1

[Command]
name = "back_z"
command = /$B,z
time = 1

[Command]
name = "down_x"
command = /$D,x
time = 1

[Command]
name = "down_y"
command = /$D,y
time = 1

[Command]
name = "down_z"
command = /$D,z
time = 1

[Command]
name = "fwd_x"
command = /$F,x
time = 1

[Command]
name = "fwd_y"
command = /$F,y
time = 1

[Command]
name = "fwd_z"
command = /$F,z
time = 1

[Command]
name = "up_x"
command = /$U,x
time = 1

[Command]
name = "up_y"
command = /$U,y
time = 1

[Command]
name = "up_z"
command = /$U,z
time = 1

[Command]
name = "back_a"
command = /$B,a
time = 1

[Command]
name = "back_b"
command = /$B,b
time = 1

[Command]
name = "back_c"
command = /$B,c
time = 1

[Command]
name = "down_a"
command = /$D,a
time = 1

[Command]
name = "down_b"
command = /$D,b
time = 1

[Command]
name = "down_c"
command = /$D,c
time = 1

[Command]
name = "fwd_a"
command = /$F,a
time = 1

[Command]
name = "fwd_b"
command = /$F,b
time = 1

[Command]
name = "fwd_c"
command = /$F,c
time = 1

[Command]
name = "up_a"
command = /$U,a
time = 1

[Command]
name = "up_b"
command = /$U,b
time = 1

[Command]
name = "up_c"
command = /$U,c
time = 1

;-| Single Button |---------------------------------------------------------
[Command]
name = "a"
command = a
time = 1

[Command]
name = "b"
command = b
time = 1

[Command]
name = "c"
command = c
time = 1

[Command]
name = "x"
command = x
time = 1

[Command]
name = "y"
command = y
time = 1

[Command]
name = "z"
command = z
time = 1

[Command]
name = "s"
command = s
time = 1

;-| Single Dir |------------------------------------------------------------
[Command]
name = "fwd" ;Required (do not remove)
command = $F
time = 1

[Command]
name = "downfwd"
command = $DF
time = 1

[Command]
name = "down" ;Required (do not remove)
command = $D
time = 1

[Command]
name = "downback"
command = $DB
time = 1

[Command]
name = "back" ;Required (do not remove)
command = $B
time = 1

[Command]
name = "upback"
command = $UB
time = 1

[Command]
name = "up" ;Required (do not remove)
command = $U
time = 1

[Command]
name = "upfwd"
command = $UF
time = 1

;-| Hold Button |--------------------------------------------------------------
[Command]
name = "hold_x"
command = /x
time = 1

[Command]
name = "hold_y"
command = /y
time = 1

[Command]
name = "hold_z"
command = /z
time = 1

[Command]
name = "hold_a"
command = /a
time = 1

[Command]
name = "hold_b"
command = /b
time = 1

[Command]
name = "hold_c"
command = /c
time = 1

[Command]
name = "hold_s"
command = /s
time = 1

;-| Hold Dir |--------------------------------------------------------------
[Command]
name = "holdfwd" ;Required (do not remove)
command = /$F
time = 1

[Command]
name = "holddownfwd"
command = /$DF
time = 1

[Command]
name = "holddown" ;Required (do not remove)
command = /$D
time = 1

[Command]
name = "holddownback"
command = /$DB
time = 1

[Command]
name = "holdback" ;Required (do not remove)
command = /$B
time = 1

[Command]
name = "holdupback"
command = /$UB
time = 1

[Command]
name = "holdup" ;Required (do not remove)
command = /$U
time = 1

[Command]
name = "holdupfwd"
command = /$UF
time = 1


; Don't remove the following line. It's required by the CMD standard.
[Statedef -1]

;===========================================================================
;---------------------------------------------------------------------------
;AI TESTING



[State -1, AI]
type = ChangeState
value = 201
triggerall = command = "AI_ATK_Back"
trigger1 = statetype = S
trigger1 = ctrl
;--------------------------------------
trigger2 = command = "holdfwd"
trigger2 = movehit
trigger2 = stateno = 203
trigger2 = hitcount =2

[State -1, AI]
type = ChangeState
value = 202
triggerall = command = "AI_ATK_Foward"
trigger1 = statetype = S
trigger1 = ctrl
;--------------------------------------
trigger2 = command != "holdback"
trigger2 = command != "holdfwd"
trigger2 = command != "holddown"
trigger2 = command != "holdup"
trigger2 = movehit
trigger2 = stateno = 206
;--------------------------------------
trigger3 = command = "holddown"
trigger3 = movehit
trigger3 = stateno = 203
trigger3 = hitcount =2

[State -1, AI]
type = ChangeState
value = 206
triggerall = command = "AI_ATK_Down"
trigger1 = statetype = S
trigger1 = ctrl
;--------------------------------------
trigger2 = command = "holdfwd"
trigger2 = movehit
trigger2 = stateno = 202
;--------------------------------------
trigger3 = command != "holdback"
trigger3 = command != "holdfwd"
trigger3 = command != "holddown"
trigger3 = command != "holdup"
trigger3 = movehit
trigger3 = stateno = 200


[State -1, AI]
type = ChangeState
value = 204
triggerall = command = "AI_ATK_Up"
trigger1 = statetype = S
trigger1 = ctrl
;--------------------------------------
trigger2 = command != "holdback"
trigger2 = command != "holdfwd"
trigger2 = command != "holddown"
trigger2 = command != "holdup"
trigger2 = movehit
trigger2 = stateno = 202


;-------------------------------
[State -1, AI]
type = ChangeState
value = 602
triggerall = command = "AI_ATK_Foward0"
trigger1 = statetype = A
trigger1 = ctrl
;==========
trigger2= stateno=  201
trigger2= movehit && time > 15
trigger2= command ="holdback"

[State -1, AI]
type = ChangeState
value = 601
triggerall = command = "AI_ATK_Down0"
trigger1 = statetype = A
trigger1 = ctrl


[State -1, AI]
type = ChangeState
value = 603
triggerall = command = "AI_ATK_Up0"
trigger1 = statetype = A
trigger1 = ctrl

;-------------------------------
[State -1, AI]
type = ChangeState
value = 888
trigger1 = command = "AI_ATK_Run"
trigger1 = statetype = S
trigger1 = ctrl

;-------------------------------
[State -1, AI]
type = ChangeState
value = 2000
trigger1 = command = "AI_SP_Down"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, AI]
type = ChangeState
value = 300
trigger1 = command = "AI_SP_Up"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, AI]
type = ChangeState
value = 500
trigger1 = command = "AI_SP_Foward"
trigger1 = statetype = S
trigger1 = ctrl

;[State -1, AI]
;type = ChangeState
;value = 350
;trigger1 = command = "AI_SP_Back"
;trigger1 = statetype = S
;trigger1 = ctrl

;-------------------------------
[State -1, AI]
type = ChangeState
value = 510
trigger1 = command = "AI_SP_Back0"
trigger1 = statetype = A
trigger1 = ctrl

[State -1, AI]
type = ChangeState
value = 305
trigger1 = command = "AI_SP_Up0"
trigger1 = statetype = A
trigger1 = ctrl

[State -1, AI]
type = ChangeState
value = 2001
trigger1 = command = "AI_SP_Down0"
trigger1 = statetype = A
trigger1 = ctrl


;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI 1]
type = ChangeState
value = 3155
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = command = "AI_OUGI1"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2


;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI2]
type = ChangeState
value = 3200
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = command = "AI_OUGI2"
trigger1 = statetype = S || statetype = A
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit  && hitcount >=2
;--------
trigger4 = statetype = A
trigger4 = stateno = 601 ||  stateno = 602 || stateno = 603 || stateno = 600
trigger4 = movehit
;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------


[State -1, OUGI3]
type = ChangeState
value = 3300
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = command = "AI_OUGI3"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit  && hitcount >=2

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------


[State -1, OUGI 4]
type = ChangeState
value = 3400
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "AI_OUGI4"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2



[State -1, OUGI 4-AIR]
type = ChangeState
value = 3410
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "AI_OUGI4"
trigger1 = statetype = A
trigger1= ctrl
;--------
trigger2 = statetype = A
trigger2 = stateno = 601 ||  stateno = 602 || stateno = 603 || stateno = 600
trigger2 = movehit
;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI 5]
type = ChangeState
value = 3500
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "AI_OUGI5"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2


;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI 6]
type = ChangeState
value = 3600
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "AI_OUGI6"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------


[State -1, OUGI 7]
type = ChangeState
value = 3700
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "AI_OUGI7"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2

[State -1, OUGI 7 AIR]
type = ChangeState
value = 3701
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "AI_OUGI7"
trigger1 = statetype = A
trigger1= ctrl
;--------
trigger2 = statetype = A
trigger2 = stateno = 601 ||  stateno = 602 || stateno = 603 || stateno = 600
trigger2 = movehit
;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI 8]
type = ChangeState
value = 3860
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "AI_OUGI8"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------




;===========================================================================
; Run Fwd


;---------------------------------------------------------------------------
; Run Fwd
[State -1, Run Fwd]
type = ChangeState
value = 100
trigger1 = command = "FF"
trigger1 = statetype = S
trigger1 = ctrl

;---------------------------------------------------------------------------
; Run Back
[State -1, Run Back]
type = ChangeState
value = 105
trigger1 = command = "BB"
trigger1 = statetype = S
trigger1 = ctrl



;===========================================================================
;---------------------------------------------------------------------------
; Taunt
[State -1, Taunt]
type = ChangeState
value = 195
triggerall = command = "s"
trigger1 = statetype != A
trigger1 = ctrl

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI1]
type = ChangeState
value = 3155
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = command = "ougi1"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2


;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI2]
type = ChangeState
value = 3200
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = command = "ougi2"
trigger1 = statetype = S || statetype = A
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit  && hitcount >=2
;--------
trigger4 = statetype = A
trigger4 = stateno = 601 ||  stateno = 602 || stateno = 603 || stateno = 600
trigger4 = movehit
;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------


[State -1, OUGI3]
type = ChangeState
value = 3300
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = command = "ougi3"
trigger1 = statetype = S
trigger1 = stateno =  40
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit  && hitcount >=2

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------


[State -1, OUGI 4]
type = ChangeState
value = 3400
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "ougi4"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2



[State -1, OUGI 4-AIR]
type = ChangeState
value = 3410
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "ougi4"
trigger1 = statetype = A
trigger1= ctrl
;--------
trigger2 = statetype = A
trigger2 = stateno = 601 ||  stateno = 602 || stateno = 603 || stateno = 600
trigger2 = movehit
;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI 5]
type = ChangeState
value = 3500
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "ougi5"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2


;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI 6]
type = ChangeState
value = 3600
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "ougi6"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------


[State -1, OUGI 7]
type = ChangeState
value = 3700
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "ougi7"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2

[State -1, OUGI 7 AIR]
type = ChangeState
value = 3701
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "ougi7"
trigger1 = statetype = A
trigger1= ctrl
;--------
trigger2 = statetype = A
trigger2 = stateno = 601 ||  stateno = 602 || stateno = 603 || stateno = 600
trigger2 = movehit
;--------

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------

[State -1, OUGI 8]
type = ChangeState
value = 3860
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "ougi8"
trigger1 = statetype = S
trigger1= ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = statetype = S && stateno = 204 && movehit && hitcount >=2

;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------
;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------;--------






  


[State -1, Stand Light Punch]
type = ChangeState
value = 888
triggerall = command = "AI_ATK_Run"
trigger1 = statetype = S
trigger1 = ctrl


[State -1, Stand Light Punch]
type = ChangeState
value = 888
triggerall = command = "x"
trigger1 = stateno =  100
trigger1 = statetype = S
trigger1 = ctrl

[State -1, usemateria_fire]
type = ChangeState
value = 2110
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall= var(20) = 1
triggerall = command != "holdback"
triggerall = command != "holdfwd"
triggerall = command != "holddown"
triggerall = command != "holdup"
triggerall = command = "b"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, usemateria_fire]
type = ChangeState
value = 2115
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall= var(20) = 3
triggerall = command != "holdback"
triggerall = command != "holdfwd"
triggerall = command != "holddown"
triggerall = command != "holdup"
triggerall = command = "b"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, usemateria_fire]
type = ChangeState
value = 2120
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall= var(20) = 2
triggerall = command != "holdback"
triggerall = command != "holdfwd"
triggerall = command != "holddown"
triggerall = command != "holdup"
triggerall = command = "b"
trigger1 = statetype = S
trigger1 = ctrl


[State -1, changemateria+]
type = ChangeState
value = 2100
triggerall = command = "holdfwd"
triggerall = command = "b"
trigger1 = statetype = S
trigger1 = ctrl

[State -1, changemateria-]
type = ChangeState
value = 2101
triggerall = command = "holdback"
triggerall = command = "b"
trigger1 = statetype = S
trigger1 = ctrl


;=================================

[State -1, Neutral]
type = ChangeState
value = 200
triggerall = command = "x"
trigger1 = command != "holdback"
trigger1 = command != "holdfwd"
trigger1 = command != "holddown"
trigger1 = command != "holdup"
trigger1 = statetype = S
trigger1 = ctrl
;--------------------------------------
trigger2 = command = "holdfwd"
trigger2 = movehit
trigger2 = stateno = 206
;--------------------------------------
trigger3 = command = "holddown"
trigger3 = movehit
trigger3 = stateno = 202
;--------------------------
trigger4 = movehit
trigger4 = command != "holdback"
trigger4 = command != "holdfwd"
trigger4 = command != "holddown"
trigger4 = command != "holdup"
trigger4 = stateno = 400
 ;-----;-----
 
 
;=================================

[State -1, Back]
type = ChangeState
value = 201
triggerall = command = "x"
trigger1 = command = "holdback"
trigger1 = statetype = S
trigger1 = ctrl
;--------------------------------------
trigger2 = command = "holdfwd"
trigger2 = movehit
trigger2 = stateno = 203
trigger2 = hitcount =2
;--------------------------
trigger3 = movehit
trigger3 = stateno = 400  &&   command = "holdback"
 ;-----;-----
 
;=================================

[State -1, Forward]
type = ChangeState
value = 202
triggerall = command = "x"
trigger1 = command = "holdfwd"
trigger1 = statetype = S
trigger1 = ctrl
;--------------------------------------
trigger2 = command != "holdback"
trigger2 = command != "holdfwd"
trigger2 = command != "holddown"
trigger2 = command != "holdup"
trigger2 = movehit
trigger2 = stateno = 206
;--------------------------------------
trigger3 = command = "holddown"
trigger3 = movehit
trigger3 = stateno = 203
trigger3 = hitcount =2
;--------------------------------------
trigger4 = movehit
trigger4 = stateno = 400  &&   command = "holdfwd"
 ;-----;-----

;=================================

;--------------------------------------
;WITH FALL
[State -1, Up]
type = ChangeState
value = 204
triggerall = command = "x"
trigger1 = command = "holdup"
trigger1 = statetype = S
trigger1 = stateno =  40
;trigger1 = ctrl
;--------------------------------------
trigger2 = command != "holdback"
trigger2 = command != "holdfwd"
trigger2 = command != "holddown"
trigger2 = command != "holdup"
trigger2 = movehit
trigger2 = stateno = 202

[State -1, Up]
type = ChangeState
value = 203
triggerall = command = "x"
trigger1 = command = "holdup"
trigger1 = statetype = S
trigger1 = stateno =  40
;trigger1 = ctrl
;--------------------------------------
trigger2 = command = "holdfwd"
trigger2 = movehit
trigger2 = stateno = 200
;--------------------------------------
trigger3 = command = "holddown"
trigger3 = movehit
trigger3 = stateno = 206
;--------------------------------------
trigger4 = movehit
trigger4 = stateno = 400  &&   command ="holdup"
 ;-----;-----



;=================================

[State -1, Down]
type = ChangeState
value = 206
triggerall = command = "x"
trigger1 = command = "holddown"
trigger1 = statetype = C
trigger1 = stateno =  10
;trigger1 = ctrl
;--------------------------------------
trigger2 = command = "holdfwd"
trigger2 = movehit
trigger2 = stateno = 202
;--------------------------------------
trigger3 = command != "holdback"
trigger3 = command != "holdfwd"
trigger3 = command != "holddown"
trigger3 = command != "holdup"
trigger3 = movehit
trigger3 = stateno = 200
;--------------------------------------
trigger4 = movehit
trigger4 = stateno = 400  &&   command ="holddown"
 ;-----;-----

;=================================



;---

[State -1, Stand Light Punch]
type = ChangeState
value = 400
triggerall = command = "x"
trigger1 = command = "holddown"
trigger1 = statetype = C
trigger1 = stateno != 40
trigger1 = ctrl
;--
trigger2= stateno= 5888 && time >10

;---
;---------------------------------------------------------------------------



[State -1, Jump Light Punch]
type = ChangeState
value = 603
triggerall = command = "x"
triggerall = command != "holddown"
trigger1 = statetype = A
trigger1 = movehit
trigger1 = stateno = 602
trigger1 = stateno != 603
trigger1 = hitcount = 2

[State -1, Jump Light Punch]
type = ChangeState
value = 602
triggerall = command = "x"
triggerall = command != "holddown"
trigger1 = statetype = A
trigger1 = movehit
trigger1 = stateno = 600
trigger1 = stateno != 602


[State -1, Jump Light Punch]
type = ChangeState
value = 601
triggerall = command = "x"
triggerall = command != "holddown"
trigger1 = statetype = A
trigger1 = movehit
trigger1 = stateno = 603
trigger1 = stateno != 601


; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 600
triggerall = command = "x"
trigger1 = command != "holddown"
trigger1 = command != "holdback"
trigger1 = command != "holdup"
trigger1 = statetype = A
trigger1 = ctrl
;==========
trigger2= stateno=  201
trigger2= movehit && time > 15
trigger2= command ="holdback"

; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 601
triggerall = command = "down_x"
trigger1 = statetype = A
trigger1 = ctrl

; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 602
triggerall = command = "back_x"
trigger1 = statetype = A
trigger1 = ctrl

; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 603
triggerall = command = "up_x"
trigger1 = statetype = A
trigger1 = ctrl

; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 1000
triggerall = command = "y"
triggerall = command != "holddown"
triggerall = command != "holdback"
triggerall = command != "holdup"
triggerall = command != "holdfwd"
trigger1 = statetype = s
trigger1 = ctrl
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype != A


; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 1010
triggerall = command = "y"
triggerall = command != "holddown"
triggerall = command != "holdback"
triggerall = command != "holdup"
triggerall = command != "holdfwd"
trigger1 = statetype = a
trigger1 = ctrl
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype = A

; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 300
triggerall = command = "y"
triggerall = command = "holdup"
trigger1 = statetype = S
trigger1 = stateno =  40
trigger1 = stateno !=  307
trigger1 = stateno !=  302
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype != A


; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 305
triggerall = command = "y"
triggerall = command != "holddown"
triggerall = command != "holdback"
triggerall = command = "holdup"
triggerall = command != "holdfwd"
trigger1 = statetype = A
trigger1 = ctrl
trigger1 = stateno !=  307
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype = A

; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 2000
triggerall = command = "y"
triggerall = command = "holddown"
triggerall = command != "holdback"
triggerall = command != "holdup"
triggerall = command != "holdfwd"
trigger1 = statetype = C
trigger1 = stateno !=  307
trigger1 = stateno !=  302
trigger1 = ctrl
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype != A


; Jump Light Punch
[State -1, Jump Light Punch]
type = ChangeState
value = 2001
triggerall = command = "y"
triggerall = command = "holddown"
triggerall = command != "holdback"
triggerall = command != "holdup"
triggerall = command != "holdfwd"
trigger1 = statetype = A
trigger1 = stateno !=  307
trigger1 = ctrl
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype = A


[State -1, Jump Light Punch]
type = ChangeState
value = 500
triggerall = command = "y"
triggerall = command != "holddown"
triggerall = command != "holdback"
triggerall = command != "holdup"
triggerall = command = "holdfwd"
trigger1 = statetype = S
trigger1 = ctrl
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype != A

[State -1, Jump Light Punch]
type = ChangeState
value = 510
triggerall = command = "y"
triggerall = command != "holddown"
triggerall = command != "holdup"
triggerall = command = "holdfwd"
trigger1 = statetype = A

trigger1 = ctrl
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype = A


[State -1, Jump Light Punch]
type = ChangeState
value = 510
triggerall = command = "y"
triggerall = command != "holddown"
triggerall = command = "holdback"
triggerall = command != "holdup"
trigger1 = statetype = A

trigger1 = ctrl
;--------
trigger2 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger2 = movehit
trigger2 = statetype = A


[State -1, CrossSlash]
type = ChangeState
value = 410
triggerall = command = "y"
triggerall = command = "holdback"
trigger1 = statetype = S
trigger1 = ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit
;--------
trigger3 = stateno = 200 ||stateno = 201 || stateno= 202 || stateno= 206 || stateno= 888 || stateno = 601 || stateno= 602 || stateno = 603 || stateno = 600
trigger3 = movehit
trigger3 = statetype != A

[State -1, CrossSlash]
type = ChangeState
value = 420
triggerall = command = "AI_SP_Back"
trigger1 = statetype = S
trigger1 = ctrl
;--------
trigger2 = statetype = S
trigger2 = stateno = 200 ||  stateno = 201 || stateno = 202 || stateno = 206 || stateno = 888
trigger2 = movehit

;[State -1, Jump Light Punch]
;type = ChangeState
;value = 685
;triggerall = command = "y"
;triggerall = command != "holdfwd"
;triggerall = command != "holddown"
;triggerall = command = "holdback"
;triggerall = command != "holdup"
;trigger1 = statetype = S
;trigger1 = ctrl
;trigger1 = var(4) = 1
;
;[State -1, Jump Light Punch]
;type = ChangeState
;value = 686
;triggerall = command = "y"
;triggerall = command != "holdfwd"
;triggerall = command != "holddown"
;triggerall = command = "holdback"
;triggerall = command != "holdup"
;trigger1 = statetype = S
;trigger1 = ctrl
;trigger1= time >=10
;trigger1 = var(4) = 2


;---------------------------------------------------------------------------
; Jump Medium Punch
;[State -1, Jump Medium Punch]
;type = ChangeState
;value = 610
;triggerall = command = "y"
;trigger1 = statetype = A
;trigger1 = ctrl
; [State -1, Jump Light Punch]
; type = ChangeState
;value = 622
;triggerall = command = "b"
;trigger1 = statetype = S
;trigger1 = ctrl


;-----------------------;-----------------------;-----------------------
;-----------------------;-----------------------;-----------------------;-----------------------
;[State -1, Call Card]
;type = ChangeState
;value = 30099
;triggerall = command = "z" && helper(30000),var(20)
;trigger1 = ctrl
;trigger1 = statetype =S
;-----------------------
[State 0, Explod]
type = Explod
triggerall = command = "z" && helper(30000),var(20) && movetype!=H
triggerall = !numhelper(130000)
triggerall = !numexplod(140000)
trigger1 = ctrl
trigger2= stateno!=[40000,50000]
anim =  F140000 + (100 * (helper(30000), var(20)))
ID = 140000
pos = 160,232
postype = left ;p2,front,back,left,right
bindtime = -1
sprpriority =5
ontop=1
ownpal = 1
supermovetime =99999999999999

;-----------------------
[State 0, Helper]
type = Helper
triggerall = command = "z" && helper(30000),var(20) && movetype!=H
triggerall = !numhelper(130000)
trigger1 = ctrl
trigger2= stateno!=[40000,50000]
helpertype = normal ;player
name = "ranker_ABC"
ID = 130000
stateno = 30000 + (helper(30000),var(20) * 100)
pos = -60,0
postype = p1    ;p2,front,back,left,right
facing = 1
keyctrl = 0
ownpal = 1


;--- use crisis card

[State -1, Jump Light Punch]
type = ChangeState
value = 7999
triggerall= life < 200
triggerall= helper(30000), var(45)>0
triggerall=  var(58) >= 1000 ;HILBERT
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(1) >= 1
triggerall = helper(20000), stateno=20001 &&   helper(20000),fvar(2) >= 1
triggerall = command = "a"
trigger1 = statetype = S
trigger1 = ctrl

;---------------------------------------------------------------------------
