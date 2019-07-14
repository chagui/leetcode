for w in `cat words.txt | tr ' ' '\n' | sort -u`; do echo "$w $(grep -w $w <(cat words.txt | tr ' ' '\n') | wc -l)"; done | sort -rnk2
