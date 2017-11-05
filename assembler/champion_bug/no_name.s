.comment	"aff, just kidding"

hello:
	sti		r1, %:alive, %1 #Mettre un REG en arg1 a la place de DIR
	fork	%:alive
	add		r2, r3, r4

alive:
	live	%0
	zjmp	%:alive
