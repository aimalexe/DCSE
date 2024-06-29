<!-- Example 1: Using PHP-MYSQL Interface -->

<?php 
   //step  Database Connection 
   //To connect to database: server name, user, and user's password 
   //must be  
   $hostname="localhost";
   $username="root";
   $password="";
   $dbname="task_4_5";
   $db=mysqli_connect($hostname,$username, $password, $dbname); 

   if(mysqli_connect_errno()){ 
      echo "Failed to connect to MySQL: ".mysqli_connect_error(); 
   } 
   else{ 
      echo "Connected..."; 
   }
   // mysql_* functions were removed as of PHP 7. 

   //step  Database Selection 
   //To select database: provide database name and connection variable 
?> 

<html> 
   <head> 
      <title> PHP MySql Basics </title> 
   </head>
   <body> 
      <?php 
         //step Perform query or operation on database 
         $sql="SELECT * FROM member";
         $result=mysqli_query($db, $sql); 

         //step Display query results 
         while($row=mysqli_fetch_array($result)){ 

            // display the data in table
         echo "<h2>".$row['MemberID']." ".$row['FirstName']."</h2>";
         } 
      ?>    
   </body> 
</html> 
<?php 
   mysqli_close($db); 
?> 