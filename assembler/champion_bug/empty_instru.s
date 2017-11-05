.name 		"laugh"
.comment	"aff, just kidding"

hello:
	sti		r1, %:alive, %1
	fork	%:alive
	add

alive:
	live	%0
	zjmp	%:alive
