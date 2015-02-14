"""
Tic-Tac-Toe Python Language Version
Programmed by bunseokbot@bob
E-Mail : admin@smishing.kr
Blog : http://blog.smishing.kr
"""
import random
import sys

set_dol = [['0', '0', '0'], ['0', '0', '0'], ['0', '0', '0']]
user_dol = "A"
com_dol = "B"

def vaildCheck():
	global set_dol, user_dol, com_dol
	if set_dol[0][0] is user_dol and set_dol[1][1] is user_dol and set_dol[2][2] is user_dol:
		print "[SYSTEM] User Win!"
		return 1

	if set_dol[0][0] is com_dol and set_dol[1][1] is com_dol and set_dol[2][2] is com_dol:
		print "[SYSTEM] Computer Win!"
		return 1
	
	if set_dol[2][0] is user_dol and set_dol[1][1] is user_dol and set_dol[0][2] is user_dol:
		print "[SYSTEM] User Win!"
		return 1

	if set_dol[2][0] is com_dol and set_dol[1][1] is com_dol and set_dol[0][2] is com_dol:
		print "[SYSTEM] Computer Win!"
		return 1

	for i in range(0, 3):
		for j in range(0, 3):
			if set_dol[i][j] is not user_dol:
				break
			if j == 2:
				print "[SYSTEM] User Win!"
				return 1

	for i in range(0, 3):
		for j in range(0, 3):
			if set_dol[i][j] is not com_dol:
				break
			if j == 2:
				print "[SYSTEM] Computer Win!"
				return 1

	for i in range(0, 3):
		for j in range(0, 3):
			if set_dol[j][i] is not user_dol:
				break
			if j == 2:
				print "[SYSTEM] User Win!"
				return 1

	for i in range(0, 3):
		for j in range(0, 3):
			if set_dol[j][i] is not com_dol:
				break
			if j == 2:
				print "[SYSTEM] Computer Win!"
				return 1	

def playgame():
	global set_dol, user_dol, com_dol
	i = 0
	while i < 9:
		if i % 2 == 0: #if user turn
			coord = raw_input("Input (x, y) location : ")

			if coord == "":
				print "Input vaild location :("
			else:
				try:
					x_coord = int(coord.split(" ")[0])
					y_coord = int(coord.split(" ")[1])
					if x_coord > 3 or y_coord > 3:
						print "Input vaild location :("
					elif set_dol[x_coord][y_coord] is "A" or set_dol[x_coord][y_coord] is "B":
						print "Input vaild location :("
					else:
						set_dol[x_coord][y_coord] = user_dol
						print "User Selected %d, %d" %(x_coord, y_coord)
						i = i + 1
						dolStatus()
						if vaildCheck() == 1:
							break
				except IndexError, sweetchip:
					print "[SYSTEM] Sweetchip?" #IE...? 
				except:
					print "Input vaild location :("
		else:
			x_coord = random.randint(0, 2)
			y_coord = random.randint(0, 2)
			if x_coord > 3 or y_coord > 3:
				pass
			elif set_dol[x_coord][y_coord] is "A" or set_dol[x_coord][y_coord] is "B":
				pass
			else:
				set_dol[x_coord][y_coord] = com_dol
				print "Computer Selected %d, %d" %(x_coord, y_coord)
				i = i + 1
				dolStatus()
				if vaildCheck() == 1:
					break


def dolStatus():
	global set_dol
	print "##################"
	print "Tic-Tac-Toe Status"
	for i in range(0, 3):
		for	j in range(0, 3):
			sys.stdout.write(set_dol[i][j] + " ")
		if i < 2:
			print ""
	print "\n##################"

def main():
	print "###########################"
	print "Welcome to Tic-Tac-Toe Game"
	print "###########################"
	dolStatus()
	playgame()

if __name__ == '__main__':
	main()
