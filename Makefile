CC = g++
CFLAGS   = -g -Wall -Wextra -pedantic
SAN_FLAG = -fsanitize=address

# main = main.cpp 
# SkillSet.cpp uses Skill.cpp uses Move.cpp + Move.h
OBJS = skillset_test.o Unit.o devFunctions.o SkillSet.o Skill.o Move.o CombatScene.o CombatEngine.o

TARGET = skillset_test
all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(SAN_FLAG) -o $(TARGET) $(OBJS)

skillset_test.o: skillset_test.cpp Unit.h CombatScene.o CombatEngine.o devFunctions.o
	$(CC) $(CFLAGS) $(SAN_FLAG) -c skillset_test.cpp

Unit.o: Unit.cpp Unit.h SkillSet.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Unit.cpp

devFunctions.o: devFunctions.cpp devFunctions.h SkillSet.h Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c devFunctions.cpp

SkillSet.o: SkillSet.cpp SkillSet.h Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c SkillSet.cpp

Skill.o: Skill.cpp Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Skill.cpp

Move.o: Move.cpp Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Move.cpp

CombatScene.o: CombatScene.cpp CombatScene.h Unit.h SkillSet.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c CombatScene.cpp
CombatEngine.o: CombatEngine.cpp CombatEngine.h CombatScene.h Unit.h SkillSet.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c CombatEngine.cpp

clean:
	rm -f $(OBJS) $(TARGET)
