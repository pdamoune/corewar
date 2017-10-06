#!/usr/bin/env python
import os
import sys

corewar = './corewar -qizvko '
corewarzaz = '../ressources/corewar -v 15 '
# corewar = './corewar -izq '
# corewarzaz = '../ressources/corewar -v 0 '

out = 'corewar.out'
outzaz = 'corewarzaz.out'

champdir = '../ressources/champs/'

fight_list = [
    ('zork.cor',),
    ('Car.cor',),
    ('Gagnant.cor',),
    ('Octobre_Rouge_V4.2.cor',),
    ('Survivor.cor',),
    ('ex.cor',),
    ('jumper.cor',),
    ('maxidef.cor',),
    ('slider2.cor',),
    ('zork.cor', 'Car.cor'),
    ('Gagnant.cor', 'jumper.cor'),
    ('ex.cor', 'maxidef.cor', 'slider2.cor',),
    ('Octobre_Rouge_V4.2.cor', 'Octobre_Rouge_V4.2.cor', 'Octobre_Rouge_V4.2.cor', 'Octobre_Rouge_V4.2.cor',),
    ]

cmd_list = [
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
    cmd = "gtimeout 2 " + cur_cmd
    return os.system(cmd)

def all_cmd_test(cur_cmd):
    # iter = 0
    for index,command in enumerate(cmd_list):
        res = my_execute(corewarzaz + command + cur_cmd + ' > ' + outzaz)
        if res == 1:
            if (check_if_ended(outzaz)):
                return (-1)
        if res == 31744:
            print "Command take too much time. next fight"
            return (index)
        res = my_execute(corewar + command + cur_cmd + ' > ' + out)
        if res == 1:
            return (1)
        if res == 31744:
            print "Command take too much time. next fight"
            return (index)
        if os.system('diff ' + out + ' ' + outzaz + ' > corewar.diff'):
            print "DIFF ON:" + command + cur_cmd
            return(-1)
    return (0)

def main_func():
    for fight in fight_list:
        cur_cmd = ''
        for champ in fight:
            if not os.path.isfile(champdir + champ):
                print champdir + champ + ': Is not a valid file'
                sys.exit(1)
            cur_cmd += ' ' + champdir + champ
        print 'Init of the fight: ' + str(fight)
        test_done = all_cmd_test(cur_cmd)
        if (test_done == -1):
            return(1)
        if (test_done):
            print "Test success: " + str(test_done) + "/" + str(len(cmd_list))
            print "We skip " + str(len(cmd_list) - test_done) + " tests because the command as timeout"
        else:
            print "All Test success (" + str(len(cmd_list)) + ")"
        print ''
    return (0)

sys.exit(main_func())