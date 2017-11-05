.name 		"laugh"
.comment	"aff, just kidding"

hello:
	sti		r1, %:alive, %1
	fork	%:alive
	addr2, r3, r4 				#les args sont colles a l'instruction

alive:
	live	%0
	zjmp	%:alive
