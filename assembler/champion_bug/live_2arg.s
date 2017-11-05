.name 		"laugh"
.comment	"aff, just kidding"

hello:
	sti		r1, %:alive, %1
	fork	%:alive
	add		r2, r3, r4

alive:
	live	%0, r3				#Ajouter un arg non autorise
	zjmp	%:alive
