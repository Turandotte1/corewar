.name "tota"
.comment "Salut j'aime les chips"

l1:		sti r1, %:live, %1
		and r1, %0, r1

live: 	live %2
		sti r1, %:fork,  %1
		zjmp %5

fork:	sti r1, %:fork, %1
		fork %:live
		sti r1, %:fork, %1
		zjmp %5
		sti r1, %:fork, %1
		zjmp %:fork

