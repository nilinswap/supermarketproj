CREATE DATABASE supmarproj;
USE supmarproj;
CREATE TABLE itemtable(
			id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
			name VARCHAR(50) NOT NULL,
			cp FLOAT NOT NULL,
			sp FLOAT NOT NULL,
			wt FLOAT NOT NULL,
			dis FLOAT DEFAULT 0);
#INSERT INTO itemtable (name,cp,sp,wt) VALUES ("DUMMY",45,25,100);

