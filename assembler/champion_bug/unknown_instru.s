.name 		"laugh"
.name 		"je ne devrais pas etre la"
.comment	"aff, just kidding"

hello:
	sti		r1, %:alive, %1
	fork	%:alive
	add		r2, r3, r4

alive:
	youyou	%0
	zjmp	%:alive
