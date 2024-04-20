/* Comparison Operators */
-- Select all members with a handicap less than 20
SELECT * FROM Member WHERE Handicap < 20;

-- Select all members with a handicap greater than or equal to 30
SELECT * FROM Member WHERE Handicap >= 30;

-- Select all members who joined before 2014
SELECT * FROM Member WHERE JoinDate <= '2014-01-01';

-- Select all tournaments where the TourID is not equal to 25
SELECT * FROM Tournament WHERE TourID != 25;


/* Boolean Operators */
-- Select all male senior members
SELECT * FROM Member WHERE Gender = 'M' AND MemberType = 'Senior';

-- Select all members who are either in Team A or Team B
SELECT * FROM Member WHERE Team = 'Team A' OR Team = 'Team B';

-- Select all members who are not juniors
SELECT * FROM Member WHERE NOT MemberType = 'Junior';


/* Special Operators */
-- Select all members with a handicap between 10 and 20
SELECT * FROM Member WHERE Handicap BETWEEN 10 AND 20;

-- Select all members whose first name starts with 'Jo'
SELECT * FROM Member WHERE FirstName LIKE 'Jo%';

-- Select all members who are in either Team A, Team B, or Team C
SELECT * FROM Member WHERE Team IN ('Team A', 'Team B', 'Team C');

-- Select all members who do not have a coach assigned
SELECT * FROM Member WHERE Coach IS NULL;

-- Select distinct types of memberships from the Member table
SELECT DISTINCT MemberType FROM Member;
