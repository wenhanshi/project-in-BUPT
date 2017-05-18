# Database Syetem

This course work includes programms on MySQL5.7 and interface with Python3.6.

You can use `stu-dump.sql` to create the database for course work.

```sql
$ mysql use [your_database_name]
$ mysql source G:/stu-dump.sql

```

---

# Content

### MySQL & Kingbase installation
### Tables & Views
e.g.
```sql
insert into student values
( '31111', '史文翰', '男', '1995-12-5 12:00', '计算机', '2333' );

```
```sql
alter table student add column dog varchar(1);
```
### Query Processing
Including nest-subquery and multi-table query.

e.g.
Find names and numbers of students who do not select 数据库原理.
```sql
select stu_no, stu_name
from student
where stu_no not in (
select stu_no
from sel natural join course
where course_name = '数据库原理' );

```
### MySQL Interface with Python
Including manipulate MySQL with Python and connections.
Using MySQLdb package on Python3.
e.g.
__Build connection between MySQL and Python.__
```Python
# 建立与数据库的连接
conn = MySQLdb.connect(
        host='localhost',
        port=3306,
        user='shiwenhan',
        passwd='sb233',
        db='stu',
        charset='utf8'
        )
```
__Execute SQL statement__
```Python
# 更新数据
c = cur.execute("update sel set grade = 100 where stu_no = '11111'")
```
__Commit transactions__
```Python
# 提交事务
conn.commit()
```
### Query Analyzing with `explain`
Good questions:
1. Which is more effective to find out the maximum of grade? `max(grade)` or `all`?
2. Which is more effective to query? nest-subquery or natural join?
3. Which is more effective when doing `insert`? clustered index, non-clustered index or without index?

### Integrity & Security, Transaction, Back-up & Recovery
Exploring integrity by:
__foreign key__
Create foreign key with  
```sql
alter table sel add constraint foreign key (stu_no) references student (stu_no);
```
__stored procedure__
```sql
create procedure show_sel (in stu_no_input varchar(5))
  begin
  select course_no
  from sel
  where stu_no = stu_no_input;
  end
```
__trigger__
```sql
create trigger add_date
  after insert on student
  for each row
  begin
  update student
  set b_date = DATA_ADD(b_date, INTERVAL 1 DAY);
  end
```
