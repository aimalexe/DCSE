-- Table creation for 'Type'
CREATE TABLE Type (
  Type VARCHAR(50) PRIMARY KEY,
  Fee DECIMAL(10, 2)
);

-- Table creation for 'Tournament'
CREATE TABLE Tournament (
  TourID INT PRIMARY KEY,
  TourName VARCHAR(100),
  TourType VARCHAR(50)
);

-- Table creation for 'Team'
CREATE TABLE Team (
  TeamName VARCHAR(100) PRIMARY KEY,
  PracticeNight VARCHAR(50),
  Manager VARCHAR(100)
);

-- Table creation for 'Member'
CREATE TABLE Member (
  MemberID INT PRIMARY KEY,
  FirstName VARCHAR(50),
  LastName VARCHAR(50),
  MemberType VARCHAR(50),
  Phone VARCHAR(15),
  Handicap INT,
  JoinDate DATE,
  Coach VARCHAR(100),
  Team VARCHAR(100),
  Gender CHAR(1),
  FOREIGN KEY (MemberType) REFERENCES Type(Type),
  FOREIGN KEY (Team) REFERENCES Team(TeamName)
);

-- Table creation for 'Entry'
CREATE TABLE Entry (
  MemberID INT,
  TourID INT,
  Year YEAR,
  PRIMARY KEY (MemberID, TourID),
  FOREIGN KEY (MemberID) REFERENCES Member(MemberID),
  FOREIGN KEY (TourID) REFERENCES Tournament(TourID)
);
