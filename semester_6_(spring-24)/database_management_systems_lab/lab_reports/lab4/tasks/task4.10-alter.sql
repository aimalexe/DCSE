-- Add new column DOB to store member date of birth. Its type is date and can be null.
ALTER TABLE Member ADD DOB DATE NULL;

-- Now change the name of newly added column from DOB to M_DOB with date as da-ta type and not null. 
ALTER TABLE Member CHANGE DOB M_DOB DATE NOT NULL;

-- Now drop the M_DOB column from member table. 
ALTER TABLE Member DROP COLUMN M_DOB;

-- Next drop the primary key TourID from tournament table. 
ALTER TABLE Tournament DROP PRIMARY KEY;

-- Now add new primary key TourID into tournament table. 
ALTER TABLE Tournament ADD PRIMARY KEY (TourID);

-- Next drop the foreign key Coach from member table. 
ALTER TABLE Member DROP FOREIGN KEY Coach;

-- Now add the new foreign key Coach from member table.
ALTER TABLE Member ADD CONSTRAINT Coach FOREIGN KEY (Coach) REFERENCES Member(Coach);
