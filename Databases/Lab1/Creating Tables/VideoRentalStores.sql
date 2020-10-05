Create database VideoRentalStores
go
use VideoRentalStores
go

CREATE TABLE Stores
(Pid INT PRIMARY KEY IDENTITY,
Name varchar(50),
City varchar(50) NOT NULL,
NoOfStores int,
NoOfClients int)

CREATE TABLE VideoCategory
(Sid INT PRIMARY KEY IDENTITY,
Type varchar(50) DEFAULT 'Mint',
NoOfVideos int)

CREATE TABLE Videos
(Cid INT PRIMARY KEY IDENTITY,
Name varchar(50),
Quantity int CHECK (Quantity=1 OR Quantity=2),
Price int,
Sid int FOREIGN KEY REFERENCES VideoCategory(Sid))

CREATE TABLE StoresVideos
(Cid INT FOREIGN KEY REFERENCES Videos(Cid),
Pid INT FOREIGN KEY REFERENCES Stores(Pid),
CONSTRAINT pk_Videos PRIMARY KEY (Cid, Pid)
)
CREATE TABLE Managers
(Mid INT FOREIGN KEY REFERENCES Stores(Pid),
Name varchar(50) NOT NULL,
Experience INT,
CONSTRAINT pk_StoresManagers PRIMARY KEY(Mid)
)