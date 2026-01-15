CC = g++
CFLAGS   = -g -Wall -Wextra -pedantic
SAN_FLAG = -fsanitize=address

# main = main.cpp 
# SkillSet.cpp uses Skill.cpp uses Move.cpp + Move.h
OBJS = skillset_test.o Unit.o SkillSet.o Skill.o Move.o

TARGET = skillset_test
all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(SAN_FLAG) -o $(TARGET) $(OBJS)

skillset_test.o: skillset_test.cpp Unit.h SkillSetGen.o
	$(CC) $(CFLAGS) $(SAN_FLAG) -c skillset_test.cpp

Unit.o: Unit.cpp Unit.h SkillSet.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Unit.cpp

SkillSetGen.o: SkillSetGen.cpp SkillSet.h Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c SkillSetGen.cpp

SkillSet.o: SkillSet.cpp SkillSet.h Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c SkillSet.cpp

Skill.o: Skill.cpp Skill.h Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Skill.cpp

Move.o: Move.cpp Move.h
	$(CC) $(CFLAGS) $(SAN_FLAG) -c Move.cpp
