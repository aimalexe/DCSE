<!-- Example 4: Using PHP-PDO Interface with  -->

<?php 
    // Step 1: Database Connection + Database Selection + Check Connection
    // Server name, user, user's password, and database must be provided.
    $username = 'root'; 
    $password = ''; 
    try 
    { 
        $str = 'mysql:host=localhost;dbname=pvfc_db;charset=utf8'; 
        $db = new PDO($str, $username, $password); 
        $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
        echo "Connected successfully";
        echo "</br>"; 
        echo "</br>"; 
    } 
    catch(PDOException $e) 
    { 
        echo "Connection failed: " . $e->getMessage(); 
    }
?>

<!DOCTYPE html> 
<html> 
    <head> 
        <title>Php-PDO Basics</title> 
    </head> 
    <body> 
        <?php 
            // Step 2: Perform query or operation on database
            $q = $db->prepare("select * from entry"); 
            $q->execute();

            // Step 3: Show result
            $q_records = $q->fetchAll(); 
            foreach ($q_records as $row){ 
                printf("%s %s\n", $row["MemberID"], $row["Year"]); 
                echo "</br>"; 
            }
        ?>
    </body> 
</html>
<?php 
    // Step 4: Close Database
    $db = null;
?>
