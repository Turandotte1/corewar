for filename in champ/*.s; do
		./asm "$filename"
	done
	for filename in champ/*.cor; do
			hexdump -c "$filename" > "$filename".txt 
		done
		echo "-------------------------------------------------\n"
		for filename in champ/*.s; do
				./asmzaz "$filename"
			done
			for filename in champ/*.cor; do
					hexdump -c "$filename" > "$filename"2.txt 
				done
				for filename in champ/*.cor; do
						diff "$filename".txt "$filename"2.txt 
					done
