(defglobal ?*numero* = 13)

(deffacts cond_ini (buscar si))

(defrule ingresar_datos
	(buscar si)
	?busc_idx <- (buscar si)
=>
	(printout t "Ingrese un numero entero del 1 al 100: " crlf)
	(assert-string ( str-cat "(usr_num " (read) ")" ))
	(retract ?busc_idx)
)

(defrule comprobar_num1
	?num_idx <- (usr_num ?num)
	(test(< ?num ?*numero*))
=>
	(printout t "El numero buscado es mayor" crlf)
	(retract ?num_idx)
	(assert (buscar si))
)

(defrule comprobar_num2
	?num_idx <- (usr_num ?num)
	(test(> ?num ?*numero*))
=>
	(printout t "El numero buscado es menor" crlf)
	(retract ?num_idx)
	(assert (buscar si))
)

(defrule comprobar_num3
	?num_idx <- (usr_num ?num)
	(test(= ?num ?*numero*))
=>
	(assert (buscar no))
	(retract ?num_idx)
)

(defrule termino
	(buscar no)
=>
	(printout t "Encontro el numero buscado" crlf)
)