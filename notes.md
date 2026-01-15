as a fun programming practice, id like to create a simple clone based off the games "Library of Runia" and "Limbus Company", which implement combat in the form of a psudo-turn based card combat system.  first, let me explain the bare basics of each combat system, as there are many similarities and id like to sort of merge them or make slight changes

Combat in LoR works:

Turn start: every unit rolls a die to determine speed, and enemy units (usually) randomly pick a player unit as their "target"

Units have 2 bars, HP and Stagger. HP reaching 0 means death. Stagger is a smaller value than hp, and also takes damage on hits (and in other cases). if stagger hits 0, the unit stops its combat and becomes "stunned" for the rest of the round, and then is unable to act during the next turn, and recovers the turn after

on a round, units have a pool of "skill cards" with a combination of 1-3 moves, comprised of


Attack -> does damage between range of X-Y (rolled during an attack)
Guard -> blocks a range of X-Y (rolled during attack)
Evade -> sets an evade of X-Y (rolled during attack)

the turns play out in a series of "clashes", with a player and an enemy unit interacting.
clash order and such depends on that earlier rolled speed dice
note that if a unit with a higher speed targets a unit with a lower speed, their targeting is redirected to make the two clash instead of the initial target
meaning that you can "force" a clash with a unit that has a lower speed, potentially defending allies or other combat skill expressions stuff


player vs enemy outcomes:
- Block < Attack = Reduced Damage (attack value - block value = taken damage)
- Block >= Attack = Fully Negate Damage, deals stagger damage equal to (block - attack = stagger taken)
- Block < or > Block = Whichever roll had the higher roll, will cause stagger damage to the lesser roll
- Block = Block = Nothing Happens

- Evade < Attack = Full Attack Damage
- Evade > Attack = Fully Evade Attack   Recover stagger equal to evade roll and it rerolls the evade die (meaning it will act as if its used again, allowing for chain evades)
- Evade = Attack = Evade Attack and Keep Evade Dice 
- Evade > Block: Recover stagger equal to evade roll but does NOT reroll the evade die

theres a few other elements of interactions, but thats the basics. some moves come alongside passive extra effects, with conditions of "on clash win, on hit, on use" and status effects like bleed and burning which ill ignore for the moment

Limbus Company works in a slightly different way, where instead of a fixed range of values just rolled:
Each skill has a Base Damage X, a coin modifier (+/-/* Y), and a number of coins (Z).
damage is calculated: flipping a coin and heads-> +/-/* Y to the base damage, dealing the the new base damage, and repeating until all coins are expended
so an example of unopposed:

Skill: x=3, y=+4, Z=2
so minimum damage = 6, (3+0) + (3+0+0)
while maximum is =18 (3+4) + (3+4+4)

on a CLASH, meaning opposed:
all coins are flipped and damage is calculated. the loser LOSES a coin, and coins are flipped again, draws just reroll without coin changes. this is repeated until one side is out of coins
then, damage is done as if it was unopposed, but only using the coins that remain (meaning if you lost 1 coin but ended up winning the clash, you now treat the skill as if it had 1 less coin)
stagger is done via checkpoints on the units HP bar, where reaching a stagger threshold triggers a stagger, with the same effects as in LoR



In addition, both games have 3 damage types (slash, pierce, blunt) which might be affcted by a units weakness/resistance to a damage type, just a flat % multiplier modifying the damage right before it would be taken to hp

