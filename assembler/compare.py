#!/usr/bin/env python
import os
import sys
import random
from shutil import copyfile

asm = './asm '
asmzaz = '../ressources/asm '
# corewar = './corewar -izq '
# corewarzaz = '../ressources/corewar -v 0 '
out = 'asm.out'
outzaz = 'asmzaz.out'

champdir = './fichiersasmtest/'

champ_list = [
    'zork.s',
    'Car.s',
    'Gagnant.s',
    'Octobre_Rouge_V4.2.s',
    'Survivor.s',
    'ex.s',
    'jumper.s',
    'maxidef.s',
    'slider2.s',
    'Asombra.s',
    'Kappa.s',
    'Machine-gun.s',
    'MarineKing.s',
    'Misaka_Mikoto.s',
    'Rainbow_dash.s',
    'THUNDER.s',
    'Varimathras.s',
    'Wall.s',
    '_.s',
    '_honeybadger.s',
    'big_feet.s',
    'casimir.s',
    'champ.s',
    'corelol.s',
    'darksasuke.s',
    'doge.s',
    'dubo.s',
    'gedeon.s',
    'jinx.s',
    'justin_bee.s',
    'littlepuppy.s',
    'live.s',
    'loose.s',
    'mandragore.s',
    'meowluigi.s',
    'salamahenagalabadoun.s',
    'sam_2.0.s',
    'skynet.s',
    'terminator.s',
    'ultimate-surrender.s',
    'youforkmytralala.s',
    ]

def my_execute(cur_cmd):
    # cmd = "gtimeout 5 " + cur_cmd
    return os.system(cur_cmd)

def all_cmd_test(cur_cmd):
    # for index,command in enumerate(cmd_list):
	skip = 0
	res = my_execute(asmzaz + cur_cmd + ' > ' + outzaz)
	if res == 1:
		# if not (check_if_ended(outzaz)):
		return (-1)
	if os.path.isfile(cur_cmd[:-1] + 'cor'):
		copyfile(cur_cmd[:-1] + 'cor' , "champ.tmp")
	else:
		skip = 1
	# if res == 31744:
	# 	print "\033[33mCommand take too much time. next fight\033[00m"
	# 	return (index)
	res = my_execute(asm + cur_cmd + ' > ' + out)
	if res == 1:
		return (-1)
	# if res == 31744:
	# 	print "\033[33mCommand take too much time. next fight\033[00m"
	# 	return (index)
	if os.system('diff ' + out + ' ' + outzaz + ' > asm.diff'):
		print "\033[31mDIFF ON: asm'" + cur_cmd + "'\033[00m"
		if skip == 1:
			return (0)
		return (-1)
	print 'file is ' + cur_cmd[:-1] + 'cor' 
	if skip == 0:
		if os.system('diff ' + cur_cmd[:-1] + 'cor' + ' ' + "champ.tmp" + ' > champ.diff'):
			print "\033[31mDIFF ON: champ '" + cur_cmd + "'\033[00m"
			os.system('hexdump champ.tmp > dumpzazout')
			os.system('hexdump ' + cur_cmd[:-1] + 'cor > dumpout')
			os.system('diff dumpout dumpzazout > hex_diff')
			return (-1)
	# if (check_if_ended(outzaz)):
	# 	print "\033[33mFight already over at command: '" + command + "'\033[00m"
	# 	return (-2)
	return (0)

def main_func():
	for champ in champ_list:
		# cur_cmd = ''
		if not os.path.isfile(champdir + champ):
			print champdir + champ + ': Is not a valid file'
			return (1)
		cur_cmd = champdir + champ
		# print 'Init of the fight: ' + cur_cmd
		test_done = all_cmd_test(cur_cmd)
		if (test_done):
			return (1)
		else:
			print "\033[32mTEST DONE: " + cur_cmd + "\033[0m"
	return (0)

sys.exit(main_func())


        # cur_cmd = ' ../ressources/champs/_.cor ../ressources/champs/ultimate-surrender.cor ../ressources/champs/littlepuppy.cor ../ressources/champs/salamahenagalabadoun.cor'
        # cur_cmd = ' ../ressources/champs/youforkmytralala.cor ../ressources/champs/justin_bee.cor ../ressources/champs/Misaka_Mikoto.cor'

# def main_func():
#     for fight in fight_list:
#         cur_cmd = ''
#         for champ in fight:
#             if not os.path.isfile(champdir + champ):
#                 print champdir + champ + ': Is not a valid file'
#                 return(1)
#             cur_cmd += ' ' + champdir + champ
#         print 'Init of the fight: ' + str(fight)
#         test_done = all_cmd_test(cur_cmd)
#         if (test_done == -1):
#             return(1)
#         if (test_done):
#             print "\033[33mTest success: " + str(test_done) + "/" + str(len(cmd_list)) + "\033[33m"
#             print "\033[33mWe skip " + str(len(cmd_list) - test_done) + " tests because the command as timeout\033[33m"
#         else:
#             print "All Test success (" + str(len(cmd_list)) + ")"
#         print ''
#     return (0)

# sys.exit(main_func())