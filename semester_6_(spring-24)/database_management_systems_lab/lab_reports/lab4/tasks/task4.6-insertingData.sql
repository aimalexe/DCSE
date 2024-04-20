-- SET FOREIGN_KEY_CHECKS = 0;

-- Inserting data into the 'Type' table
INSERT INTO Type (Type, Fee) VALUES
('Associate', 60),
('Junior', 150),
('Senior', 300),
('Social', 50);

-- Inserting data into the 'Tournament' table
INSERT INTO Tournament (TourID, TourName, TourType) VALUES
(24, 'Leeston', 'Social'),
(25, 'Kaiapoi', 'Social'),
(36, 'WestCoast', 'Social'),
(38, 'Canterburry', 'Open'),
(40, 'Otago', 'Open');


-- Inserting data into the 'Team' table
INSERT INTO Team (TeamName, PracticeNight, Manager) VALUES
('Team A', 'Tuesday', 239),
('Team B', 'Monday', 153);

-- Inserting data into the 'Member' table
INSERT INTO Member (MemberID, LastName, FirstName, Handicap, Gender, MemberType, Team, Coach, Phone, JoinDate) VALUES
(118, 'McKenzie', 'Melissa', 30, 'F', 'Junior', NULL, 153, 963270, '2009-05-10'),
(138, 'Stone', 'Michael', 30, 'M', 'Senior', 235, NULL, 982732, '2013-05-13'),
(153, 'Nolan', 'Brenda', 11, 'F', 'Senior', 153, NULL, 464249, '2010-07-15'),
(159, 'Branch', 'Helen', 14, 'F', 'Senior', 153, NULL, 482914, '2013-01-15'),
(178, 'Back', 'Sarah', NULL, 'F', 'Social', NULL, NULL, 226559, '2014-06-15'),
(228, 'Button', 'Sandra', 26, 'F', 'Junior', NULL, 153, 244493, '2015-06-21'),
(235, 'Cooper', 'William', 19, 'M', 'Senior', 153, NULL, 722540, '2012-12-01'),
(239, 'Spencer', 'Thomas', 25, 'M', 'Junior', NULL, NULL, 699234, '2011-04-01'),
(258, 'Olson', 'Barbara', 16, 'F', 'Senior', NULL, NULL, 377018, '2014-07-15'),
(286, 'Pollard', 'Robert', 19, 'M', 'Senior', 235, NULL, 616586, '2011-12-15'),
(290, 'Buxton', 'Thomas', 14, 'M', 'Senior', 235, NULL, 268593, '2012-07-15'),
(331, 'Schmidt', 'Deborah', 25, 'F', 'Senior', 153, NULL, 876497, '2013-03-01'),
(339, 'Young', 'Betty', 21, 'F', 'Senior', NULL, NULL, 507813, '2013-03-15'),
(414, 'Gilmore', 'Jane', 5, 'F', 'Social', NULL, NULL, 459558, '2012-01-01'),
(415, 'Taylor', 'William', 7, 'M', 'Senior', 235, NULL, 197536, '2011-09-01'),
(461, 'Reed', 'Robert', 23, 'M', 'Junior', NULL, NULL, 133454, '2014-08-15'),
(469, 'Willis', 'Carolyn', 29, 'F', 'Junior', NULL, NULL, 688378, '2014-12-15'),
(487, 'Kent', 'Susan', 28, 'F', 'Social', NULL, NULL, 707217, '2014-09-15');

-- Inserting data into the 'Entry' table
INSERT INTO Entry (MemberID, TourID, Year) VALUES
(118, 24, 2013),
(228, 24, 2014),
(235, 25, 2014),
(235, 36, 2012),
(235, 38, 2014),
(235, 40, 2012),
(239, 24, 2013),
(239, 25, 2014),
(258, 24, 2013),
(258, 36, 2012),
(286, 24, 2013),
(286, 25, 2012),
(286, 36, 2014),
(286, 38, 2014),
(286, 40, 2012),
(415, 24, 2013),
(415, 25, 2013),
(415, 36, 2014),
(415, 38, 2012),
(415, 40, 2014);

-- SET FOREIGN_KEY_CHECKS = 1;
