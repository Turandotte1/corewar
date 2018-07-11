.name "zork"
.comment "I'M ALIIIIVE"

l2:		st#i r1, %:live, %1
l2:		st#i r1, %:live, %1
		and r1, %0, r9
		and r1, %0, r9

live:	live %1
		zjmp %:live
live:	live %1
live:	live %1
live:	live %1
live:	live %1
live:	live %1
live:	live %1
		zjmp %:live
