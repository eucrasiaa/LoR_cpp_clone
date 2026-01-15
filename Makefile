CC = g++
CFLAGS   = -g -Wall -Wextra -pedantic
SAN_FLAG = -fsanitize=address

# main = main.cpp 
# SkillSet.cpp uses Skill.cpp uses Move.cpp + Move.h

all: skillset_test

skillset_test: skillset_test.cpp Unit.o
	$(CC) $(CFLAGS) $(SAN_FLAG) -o skillset_test skillset_test.cpp SkillSet.o Skill.o Move.o
Unit.o: Unit.cpp Unit.h SkillSet.h 
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Unit.cpp
SkillSet.o: SkillSet.cpp SkillSet.h Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c SkillSet.cpp
Skill.o: Skill.cpp Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Skill.cpp
Move.o: Move.cpp Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Move.cpp

SkillSetGen.o: SkillSetGen.cpp SkillSet.h Skill.h Move.h
