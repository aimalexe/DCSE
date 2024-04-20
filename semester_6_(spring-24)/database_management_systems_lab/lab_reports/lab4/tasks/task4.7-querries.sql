-- Here are the SQL queries for each of the requested operations:

-- a) List the first name, last name, and phone numbers of all the members.
SELECT FirstName, LastName, Phone FROM Member;

-- b) List complete information of all the male members.
SELECT * FROM Member WHERE Gender = 'M';

-- c) List complete information of all the members who joined after 01-01-2013.
SELECT * FROM Member WHERE JoinDate > '2013-01-01';

-- d) List the name of all the members who belonged to Team A.
SELECT FirstName, LastName FROM Member WHERE Team = 'Team A';

-- e) List complete information of all the senior members.
SELECT * FROM Member WHERE MemberType = 'Senior';

-- f) List complete information of all the members in order of LastName.
SELECT * FROM Member ORDER BY LastName;

-- g) Retrieve the number of records in the Member table.
SELECT COUNT(*) FROM Member;


-- h) Provide the first name and last name of the two coaches. (Assuming coaches' MemberIDs are known, for example, 239 and 153)
SELECT FirstName, LastName FROM Member WHERE MemberID IN (239, 153);

-- i) Find the amount of fee provided by each member by mentioning member first name, last name, and fee. (Assuming the `MemberType` column in `Member` table corresponds to the `Type` in `Type` table)
SELECT M.FirstName, M.LastName, T.Fee 
FROM Member M 
JOIN Type T ON M.MemberType = T.Type;

-- j) Delete the record from the Entry table where Member=415 and TourID=40.
DELETE FROM Entry WHERE MemberID = 415 AND TourID = 40;

-- k) Update the Fee of Associate in the Type table from 60 to 80.
UPDATE Type SET Fee = 80 WHERE Type = 'Associate';