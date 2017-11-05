.name 		"laugh"
.comment	"aff, just kidding"

hello:
	sti		r1, %:alive, %–2147483649
	fork	%:alive
	add		r2, r3, r4

alive:
	live	%0
	zjmp	%:alive
