package MainPackage;

import java.sql.*;

public class Database {

    GamePanel gp;

    String user="RDBMS_project";
    String password="1138";

    Connection con;
    public Database(GamePanel gp)
    {
        this.gp=gp;

        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
            con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", user, password);
        } catch (SQLException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    private ResultSet getQueryResult (String query) {
        ResultSet rs = null;

        try {

            Statement stmt = con.createStatement();

            rs = stmt.executeQuery(query);
        } catch(Exception e)
        {
            System.out.println(e);
        }

        return rs;
    }

    public void getPlayer () throws SQLException {

        ResultSet rs = getQueryResult("select * from player where save_game_id = " + gp.save_game_id);



        if(rs!=null)
        while(rs.next()){
            gp.player.BoyWorldX = rs.getInt(2);
            gp.player.BoyWorldY = rs.getInt(3);
            gp.player.GirlWorldX = rs.getInt(4);
            gp.player.GirlWOrldY = rs.getInt(5);
            gp.player.current_health=rs.getInt(6);
            gp.player.girl_current_health=rs.getInt(7);

        }
    }

    public void getInventory () throws SQLException {

        ResultSet rs = getQueryResult("select * from inventory where save_game_id = " + gp.save_game_id);



        if(rs!=null)
            while(rs.next()){

                int id= rs.getInt(1);

                gp.player.inventory[id]=rs.getInt(2);

            }
    }

    public void getEnemy () throws SQLException {

        ResultSet rs = getQueryResult("select * from destroyed_enemies where save_game_id = " + gp.save_game_id);

        for(int i=0; i<gp.enemy_count; i++)
            gp.destroyed_enemy[i]=0;

        if(rs!=null)
            while(rs.next()){

                int id= rs.getInt(1);

                gp.destroyed_enemy[id]=1;

            }

        for(int i=0; i<gp.enemy_count; i++)
        {
            if(gp.destroyed_enemy[i]==1)
                gp.enemy[i]=null;
        }
    }

    public void getQuest () throws SQLException {

        ResultSet rs = getQueryResult("select * from quest_status where save_game_id = " + gp.save_game_id);



        if(rs!=null)
            while(rs.next()){

                int id= rs.getInt(1);

                gp.quest.quest[id].status=rs.getString(2);
                gp.quest.quest[id].current_phase=rs.getInt(3);
                gp.quest.quest[id].remaining_time=rs.getInt(4);


            }
    }



    public void deleteGame(int delete_id) throws SQLException{

        getQueryResult("delete from save_game where id = " + delete_id);
        getQueryResult("delete from player where save_game_id =  " + delete_id);
        getQueryResult("delete from object_status where save_game_id = " + delete_id);
        getQueryResult("delete from destroyed_enemies where save_game_id="+delete_id);
        getQueryResult("delete from inventory where save_game_id="+delete_id);
        getQueryResult("delete from quest_status where save_game_id="+delete_id);
        getQueryResult("update save_game set id=id-1 where id > " + delete_id);
        getQueryResult("update player set save_game_id=save_game_id-1 where save_game_id > " + delete_id);
        getQueryResult("update object_status set save_game_id=save_game_id-1 where save_game_id > " + delete_id);
        getQueryResult("update quest_status set save_game_id=save_game_id-1 where save_game_id > " + delete_id);
        getQueryResult("update destroyed_enemies set save_game_id=save_game_id-1 where save_game_id > " + delete_id);
        getQueryResult("update inventory set save_game_id=save_game_id-1 where save_game_id > " + delete_id);

        gp.total_save_game--;



    }

    public void getSaveGames() throws SQLException {

        ResultSet rs = getQueryResult("Select nvl(count(*),0) from save_game");

        while(rs.next()){

            gp.total_save_game=rs.getInt(1);
        }

         rs = getQueryResult("Select * from save_game");

        int i=0;

        if(rs!=null)
        while(rs.next())
        {
            gp.saveLoading.save[i].save_id=rs.getInt(1);
            gp.saveLoading.save[i].save_name=rs.getString(2);
            gp.saveLoading.save[i].last_saved=rs.getString(3);
            gp.saveLoading.save[i].save_time=rs.getInt(4);
            gp.saveLoading.save[i].location=rs.getString(5);


            i++;
        }

    }

    public void updateSaveGames() throws SQLException {



        ResultSet rs = getQueryResult("Select * from save_game");

        int i=0;

        if(rs!=null)
        while(rs.next())
        {
            gp.saveLoading.save[i].save_id=rs.getInt(1);
            gp.saveLoading.save[i].save_name=rs.getString(2);
            gp.saveLoading.save[i].last_saved=rs.getString(3);
            gp.saveLoading.save[i].save_time=rs.getInt(4);
            gp.saveLoading.save[i].location=rs.getString(5);

            i++;
        }

    }



    public void createNewGames () throws SQLException
    {



        int id= gp.total_save_game;

        String location=gp.tileM.get_current_location();
        String name;

        if(gp.quest.current_active_quest_id>=0)
            name=gp.quest.quest[gp.quest.current_active_quest_id].name;
        else
            name="Wandering Aimlessly";
        String last_save= "to_char(sysdate, 'MONTH DD, YYYY HH:MI PM')";
        int game_time=gp.saveLoading.save[0].save_time+ gp.passed_time;
        int current_active_quest=gp.quest.current_active_quest_id;


        gp.passed_time=0;

        gp.total_save_game++;

        //String upd = "insert into save_game values (" +id + ",'" + name+"','"+last_save+"',"+game_time+",'" +location+  "')";
        String upd = "insert into save_game values ("+id+", '"+ name+"',"+last_save+" , "+game_time+", '"+location+"',"+current_active_quest+")";
        try {


            Statement stmt = con.createStatement();

            stmt.executeUpdate(upd);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    public void overwriteSaveGames () throws SQLException
    {



        int id= gp.save_game_id;

        String location=gp.tileM.get_current_location();


        String name;

        if(gp.quest.current_active_quest_id>=0)
            name=gp.quest.quest[gp.quest.current_active_quest_id].name;
        else
            name="Wandering Aimlessly";

        String last_save= "to_char(sysdate, 'MONTH DD, YYYY HH:MI PM')";
        int game_time=gp.saveLoading.save[0].save_time+ gp.passed_time;
        int current_active_quest=gp.quest.current_active_quest_id;

        gp.passed_time=0;


        getQueryResult("delete from save_game where id =  " + id);




        //String upd = "insert into save_game values (" +id + ",'" + name+"','"+last_save+"',"+game_time+",'" +location+  "')";
        String upd = "insert into save_game values ("+id+", '"+ name+"',"+last_save+" , "+game_time+", '"+location+"',"+current_active_quest+")";
        try {


            Statement stmt = con.createStatement();

            stmt.executeUpdate(upd);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }




    public void getObject () throws SQLException {

        ResultSet rs = getQueryResult("select * from object_status where save_game_id = " + gp.save_game_id);





        while(rs.next()){


            if(rs.getInt(2)!=4)
            gp.objM.world_obj[0][rs.getInt(1)].current_state=rs.getInt(2);
            else
                gp.objM.world_obj[0][rs.getInt(1)]=null;

        }


    }

    public void setPlayer () throws SQLException {

        getQueryResult("delete from player where save_game_id =  " + gp.save_game_id);

        String upd = "insert into player values (" +gp.save_game_id+", " +gp.player.BoyWorldX + "," + gp.player.BoyWorldY + "," + gp.player.GirlWorldX + ","+ gp.player.GirlWOrldY+ ", "+ gp.player.current_health+ ", "+ gp.player.girl_current_health+  ","+gp.save_game_id+")";
        try {


            Statement stmt = con.createStatement();

            stmt.executeUpdate(upd);
        } catch (SQLException  e) {
            throw new RuntimeException(e);
        }


    }



    public void setQuest () throws SQLException{

        getQueryResult("delete from quest_status where save_game_id = " + gp.save_game_id);


        try {


            Statement stmt = con.createStatement();

            for(int i=0; i<gp.quest.max_quest; i++) {

                if(gp.quest.quest[i]!=null)
                {
                    String status=gp.quest.quest[i].status;
                    int phase=gp.quest.quest[i].current_phase;
                    int time=gp.quest.quest[i].remaining_time;

                    String upd = "insert into quest_status values (" + i + ",'" + status + "',"+ phase + ","+ time + ","+gp.save_game_id+")";
                    stmt.executeUpdate(upd);

                }

            }
        } catch (SQLException  e) {
            throw new RuntimeException(e);
        }
    }

    public void setEnemy () throws SQLException{

        getQueryResult("delete from destroyed_enemies where save_game_id = " + gp.save_game_id);


        try {


            Statement stmt = con.createStatement();

            for(int i=0; i<gp.enemy_count; i++) {

               if(gp.destroyed_enemy[i]==1)
                {


                    String upd = "insert into destroyed_enemies values (" + i + "," +gp.save_game_id+")";
                    stmt.executeUpdate(upd);

                }

            }
        } catch (SQLException  e) {
            throw new RuntimeException(e);
        }
    }


    public void setInventory () throws SQLException{

        getQueryResult("delete from inventory where save_game_id = " + gp.save_game_id);


        try {


            Statement stmt = con.createStatement();

            for(int i=0; i<gp.player.invetory_size; i++) {

                if(gp.quest.quest[i]!=null)
                {

                    int amount=gp.player.inventory[i];

                    String upd = "insert into inventory values (" + i + "," + amount + ","+ gp.save_game_id+")";
                    stmt.executeUpdate(upd);

                }

            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }



    public void setObject () throws SQLException{

            getQueryResult("delete from object_status where save_game_id = " + gp.save_game_id);


                try {


                    Statement stmt = con.createStatement();

                    for(int i=0; i<gp.objM.current_obj; i++) {
                        if(gp.objM.world_obj[0][i]!=null) {

                            String upd = "insert into object_status values (" + i + "," + gp.objM.world_obj[0][i].current_state + ","+gp.save_game_id+")";
                            stmt.executeUpdate(upd);
                        }
                        else
                        {
                            String upd = "insert into object_status values (" + i + ",4,"+gp.save_game_id+")";
                            stmt.executeUpdate(upd);
                        }

                    }
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }
            }




            public void getDatabaseValues(int current_slot)
            {
                try
                {

                    gp.save_game_id=current_slot;

                    updateSaveGames();

                    getActiveQuest();
                    getPlayer();
                    getObject();
                    getEnemy();
                    getInventory();
                    getQuest();





                }
                catch (SQLException e) {
                    throw new RuntimeException(e);
                }
            }

    public void getActiveQuest() throws SQLException {

        ResultSet rs = getQueryResult("Select current_active_quest from save_game where id = "+gp.save_game_id);




        if(rs!=null)
            while(rs.next())
            {
               gp.quest.current_active_quest_id=rs.getInt(1);





            }

    }

            public void setDatabaseValues()
            {
                try
                {

                    gp.db.setPlayer();
                    gp.db.setObject();
                    gp.db.setInventory();
                    gp.db.setQuest();
                    gp.db.setEnemy();

                }
                catch (SQLException e) {
                    throw new RuntimeException(e);
                }
            }

    }

