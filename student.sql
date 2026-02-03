drop database if exists student;

create database student; 
use student;

create table if not exists Student(
	sid varchar(25) primary key,
	name varchar(35) not null,
	branch varchar(25) not null,
	semester int not null,
	address varchar(255),
	phone varchar(35),
	email varchar(50)
);

-- Inserting new students
insert into Student values
("1","Paul", "CSE", 5, "Kuvempunagar", "876543219", "paul167@gmail.com"),
("2","Darshan", "CSE", 1, "Hebbal", "9876543210", "darshansgowda179@gmail.com"),
("3","Narendra", "ME", 5, "Kuvempunagar", "8657432190", "narendraxyz@gmail.com"),
("4","Kartik", "ISE", 6, "Bangalore", "8657432190", "kartikkk@gmail.com");

-- Modify Address of the student based on SID
update Student set address="Vijayanagar" where sid = "2";

-- Delete a student
delete from Student where sid="4";

-- List All the students
select * from Student;

-- List All Students of CSE Branch
select * from Student where branch="CSE";

-- List All Students of CSE Branch who reside in Kuvempunagar
select * from Student where branch="CSE" and address="Kuvempunagar";
