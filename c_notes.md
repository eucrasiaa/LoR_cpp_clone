
Unit:
Has SkillSet


SkillSet:
 pool of Skills 

Skill:
    name, set of 1-4 Moves

Move: 
    attack type, dmg ranges, effects, etc


Combat Scene:
    units (player)
    units (enemy)
    

CombatEngine:
    init (Combat Scene)
    resolves actions (updates scene)


unit has combat states:
turn initialize (speed rolled, effects at begining of turn, stagger resolved possibly)
