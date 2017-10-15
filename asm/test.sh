#!/bin/sh
echo "\033[36m\n-----------------------------------" > debug
echo "******  Liste des champions *******" >> debug
echo "-----------------------------------" >> debug

# $list = ls | grep "\.s$"
i = 0
for champ in $( cat champions )
do
	i=$((i+1));
done
echo "Nombre de champions testés : $i\033[00m\n" >> debug

error = 0
success = 0
zaz = 0

for champ in $( cat champions )
do
	echo "\033[36m"$champ".s \n\033[00m" >> debug
	# read -p ../ressources/asm fichiersasmtest/$champ.s message
	messagezaz=$(../ressources/asm fichiersasmtest/$champ.s)
	if [ -f fichiersasmtest/$champ.cor ]
	then
		echo $champ".cor a été compilé" >> debug
		hexdump fichiersasmtest/$champ.cor > asmzaz
		messageus=$(./asm fichiersasmtest/$champ.s | tail -n 5)
		if [ -f "fichiersasmtest/"$champ"1.cor" ]
		then
			echo $champ"1.cor a été compilé" >> debug
			hexdump "fichiersasmtest/"$champ"1.cor" > asmtest
			if [ diff asmtest asmzaz > diff ]
			then
				echo "\033[31mChampion $champ / ERREUR : KO\033[00m" >> debug
				error=$((error+1));
			else
				echo "\033[32mChampion $champ / Différence : OK\033[00m" >> debug
				sucess=$((sucess+1));
			fi
		else
			echo "\033[31mERREUR : "$champ"1.cor NOT Found\033[00m" >> debug
			echo "\033[31m"$messageus"\033[00m" >> debug
			error=$((error+1));
		fi
	else
		echo "\033[33mERREUR : "$champ".cor NOT Found\033[00m" >> debug
		echo "\033[33m"$messagezaz"\033[00m" >> debug
		messageus=$(./asm fichiersasmtest/$champ.s | tail -n 5)
		if [ -f "fichiersasmtest/"$champ"1.cor" ]
		then
			echo $champ"1.cor a été compilé" >> debug
		else
			echo "\033[31mERREUR : "$champ"1.cor NOT Found\033[00m" >> debug
		fi
		echo "\033[33m"$messageus"\033[00m" >> debug
		zaz=$((zaz+1));
	fi
	echo "--------------------" >> debug
done
echo "\n" >> debug
echo "\033[36mSCORES : \033[00m" >> debug
echo "\033[32mSucess : $sucess/$i\033[00m" >> debug
echo "\033[31mError : $error/$i\033[00m" >> debug
echo "\033[33mGestion des erreurs : $zaz/$i\033[00m" >> debug
echo "--------------------" >> debug
cat debug


# for champ in $( cat champions )
# do
# 	echo "--------------------" >> debug
# 	echo "\033[36m"$champ".s \n\033[00m" >> debug
# 	./asm fichiersasmtest/$champ.s
# 	if [ -f "fichiersasmtest/"$champ"1.cor" ]
# 	then
# 		echo $champ"1.cor a été compilé" >> debug
# 		hexdump "fichiersasmtest/"$champ"1.cor" > asmtest
# 		../ressources/asm fichiersasmtest/$champ.s
# 		if [ -f fichiersasmtest/$champ.cor ]
# 		then
# 			echo $champ".cor a été compilé" >> debug
# 			hexdump fichiersasmtest/$champ.cor > asmzaz
# 			if [ diff asmtest asmzaz > diff ]
# 			then
# 				echo "\033[31mChampion $champ / ERREUR : KO\033[00m" >> debug
# 			else
# 				echo "\033[32mChampion $champ / Différence : OK\033[00m" >> debug
# 			fi
# 		else
# 			echo "\033[31mERREUR : $champ.cor NOT Found\033[00m" >> debug
# 		fi
# 	else
# 		echo "\033[31mERREUR : "$champ"1.cor NOT Found\033[00m" >> debug
# 	fi
# done
# echo "--------------------" >> debug
# cat debug
