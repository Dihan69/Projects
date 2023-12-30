connect / as sysdba;

CREATE User RDBMS_project identified by 1138;
GRANT all privilege TO RDBMS_project;

disc;

conn RDBMS_project/1138;

drop table object_status;
drop table player;
drop table quest_status;
drop table destroyed_enemies;
drop table inventory;
drop table save_game;

CREATE TABLE Save_game
(
id int primary key,
name varchar2(30),
last_save varchar2(30),
game_time int,
location varchar2(30),
current_active_quest int
);

insert into Save_game values(0, 'INTRODUCTION',to_char(sysdate, 'MONTH DD, YYYY HH:MI PM') , 0, 'Village', 1);

CREATE TABLE Player
(
player_id int,
boyX int,
boyY int,
girlX int,
girlY int,
boyCurrentHealth int,
girlCurrentHealth int,
save_game_id int unique not null
);

delete from player;
insert into Player values(0,1200,1260, 1260,1165,50,50,0);

CREATE TABLE object_status
(
object_id int,
object_status int,
save_game_id int
);

CREATE TABLE quest_status
(
quest_id int,
quest_status varchar2(20),
quest_phase varchar2(20),
quest_reamining_time int,
save_game_id int
);

CREATE TABLE destroyed_enemies
(
enemy_id int,
save_game_id int
);

CREATE TABLE inventory
(
inventory_id int,
amount int,
save_game_id int
);

commit;