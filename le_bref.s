.name "Pépin Le Bref"
.comment "Un pépin dans le noyau"

	sti r1,%:pepin,%1
pepin: live %1
	zjmp %:pepin
