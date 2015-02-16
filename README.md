# AbstractVm

AbstractVM est une machine a pile capable de calculer des expressions arithmetiques simples. 

>cat sample.avm<br/>
; -------------<br/>
; sample.avm -<br/>
; -------------<br/>
push int32(42)<br/>
push int32(33)<br/>
add<br/>
push float(44.55)<br/>
mul<br/>
push double(42.42)<br/>
push int32(42)<br/>
dump<br/>
pop<br/>
assert double(42.42)<br/>
exit<br/>

>./avm ./sample.avm<br/>
42<br/>
42.42<br/>
3341.25<br/>

>./avm<br/>
pop<br/>
;;<br/>
Line 1 : Error : Pop on empty stack<br/>
><br/>
