#!/usr/bin/env python
import os
import sys
import random

corewar = './corewar -izvko '
corewarzaz = '../ressources/corewar -a -v 15 '
# corewar = './corewar -izq '
# corewarzaz = '../ressources/corewar -v 0 '
out = 'corewar.out'
outzaz = 'corewarzaz.out'

champdir = '../ressources/champs/'

fight_list = [
    'zork.cor',
    'Car.cor',
    'Gagnant.cor',
    'Octobre_Rouge_V4.2.cor',
    'Survivor.cor',
    'ex.cor',
    'jumper.cor',
    'maxidef.cor',
    'slider2.cor',
    'championships/Asombra.cor',
    'championships/Kappa.cor',
    'championships/Machine-gun.cor',
    'championships/MarineKing.cor',
    'championships/Misaka_Mikoto.cor',
    'championships/Rainbow_dash.cor',
    'championships/THUNDER.cor',
    'championships/Varimathras.cor',
    'championships/Wall.cor',
    'championships/_.cor',
    'championships/_honeybadger.cor',
    'championships/big_feet.cor',
    'championships/casimir.cor',
    'championships/champ.cor',
    'championships/corelol.cor',
    'championships/darksasuke.cor',
    'championships/doge.cor',
    'championships/dubo.cor',
    'championships/gedeon.cor',
    'championships/jinx.cor',
    'championships/justin_bee.cor',
    'championships/littlepuppy.cor',
    'championships/live.cor',
    'championships/loose.cor',
    'championships/mandragore.cor',
    'championships/meowluigi.cor',
    'championships/salamahenagalabadoun.cor',
    'championships/sam_2.0.cor',
    'championships/skynet.cor',
    'championships/terminator.cor',
    'championships/ultimate-surrender.cor',
    'championships/youforkmytralala.cor',
    ]

cmd_list = [
        '-d 50 ',
        '-d 500 ',
        '-d 1000 ',
        '-d 2000 ',
        '-d 5000 ',
        '-d 50000 ',
        ' ',
        ]


def check_if_ended(file):
    stdin,stdout = os.popen2("tail -n 1 "+file + " | head -c 10")
    stdin.close()
    lines = stdout.readlines(); stdout.close()
    if lines == "Contestant":
        return 1
    return 0

def my_execute(cur_cmd):
    # print 'I will execute: \"' + str + '\"'
    cmd = "gtimeout 5 " + cur_cmd
    return os.system(cmd)

def all_cmd_test(cur_cmd):
    # iter = 0
    for index,command in enumerate(cmd_list):
        res = my_execute(corewarzaz + command + cur_cmd + ' > ' + outzaz)
        if res == 1:
            if (check_if_ended(outzaz)):
                return (-1)
        if res == 31744:
            print "\033[33mCommand take too much time. next fight\033[00m"
            return (index)
        res = my_execute(corewar + command + cur_cmd + ' > ' + out)
        if res == 1:
            return (1)
        if res == 31744:
            print "\033[33mCommand take too much time. next fight\033[00m"
            return (index)
        if os.system('diff ' + out + ' ' + outzaz + ' > corewar.diff'):
            print "\033[31mDIFF ON: '" + command + cur_cmd + "'\033[00m"
            return (-1)
    return (0)

def main_func(final):
    iter = 0
    while iter < final:
        iter = iter + 1
        cur_cmd = ''
        fight = random.sample(fight_list, random.randint(2, 4))
        for champ in fight:
            if not os.path.isfile(champdir + champ):
                print champdir + champ + ': Is not a valid file'
                return (1)
            cur_cmd += ' ' + champdir + champ
        cur_cmd = ' ../ressources/champs/championships/youforkmytralala.cor ../ressources/champs/championships/justin_bee.cor ../ressources/champs/championships/Misaka_Mikoto.cor'
        print 'Init of the fight: ' + str(fight)
        test_done = all_cmd_test(cur_cmd)
        if (test_done == -1):
            return (1)
        if (test_done):
            print "\033[33mTest success: " + str(test_done) + "/" + str(len(cmd_list)) + "\033[00m"
            print "\033[33mWe skip " + str(len(cmd_list) - test_done) + " tests because the command as timeout\033[00m"
        else:
            print "All Test success (" + str(len(cmd_list)) + ")"
        print "\033[32mTEST DONE: " + str(iter) + "/" + str(final) + "\033[0m"
        print ''
    return (0)

sys.exit(main_func(int(sys.argv[1])))


        # cur_cmd = ' ../ressources/champs/championships/_.cor ../ressources/champs/championships/ultimate-surrender.cor ../ressources/champs/championships/littlepuppy.cor ../ressources/champs/championships/salamahenagalabadoun.cor'
        # cur_cmd = ' ../ressources/champs/championships/youforkmytralala.cor ../ressources/champs/championships/justin_bee.cor ../ressources/champs/championships/Misaka_Mikoto.cor'

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