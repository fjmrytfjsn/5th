# task6-5

支店ごとに売り上げの多かった年度順位

## ソースコード

```MySQL
create table person_sales(
    year int not null,
    emp_id int not null,
    branch varchar(10),
    sale int,
    primary key (year,emp_id)
);
insert into person_sales values(2010,1,'支店1',50);
insert into person_sales values(2010,2,'支店1',21);
insert into person_sales values(2010,3,'支店1',30);
insert into person_sales values(2010,4,'支店2',21);
insert into person_sales values(2011,1,'支店1',60);
insert into person_sales values(2011,2,'支店1',41);
insert into person_sales values(2011,3,'支店1',20);
insert into person_sales values(2011,4,'支店2',31);

select RANK() over (partition by branch order by sum(sale) desc) as num, year, branch, sum(sale) from person_sales group by branch, year;

```

## 出力

| num | year | branch | sum(sale) |
| --- | ---- | ------ | --------- |
| 1   | 2011 | 支店1    | 121       |
| 2   | 2010 | 支店1    | 101       |
| 1   | 2011 | 支店2    | 31        |
| 2   | 2010 | 支店2    | 21        |
