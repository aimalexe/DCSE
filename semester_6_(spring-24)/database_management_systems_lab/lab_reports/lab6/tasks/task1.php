<!-- Complete Example 3 by providing a suitable query, its result, and then freeing result variable.  -->

<?php 
    // Step 1: Database Connection + Database Selection + Check Connection 
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "task_4_5";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    } 
    echo "Connected successfully";
    echo "</br>";
    echo "</br>";
?> 

<!DOCTYPE html> 
<html> 
    <head> 
        <title>MySQLi OO Basics</title> 
    </head> 
    <body> 
    <?php 
        // Step 2: Perform a query or operation on the database
        // Query to join member and entry tables and fetch details for a specific year
        $year = 2012;
        $query = "SELECT m.FirstName, m.LastName, e.TourID, e.Year FROM member m JOIN entry e ON m.MemberID = e.MemberID WHERE e.Year = ?";
        $stmt = $conn->prepare($query);
        $stmt->bind_param("i", $year);
        $stmt->execute();
        $result = $stmt->get_result();

        // Step 3: Show result
        if ($result->num_rows > 0) {
            echo "<table border='1'><tr><th>First Name</th><th>Last Name</th><th>Tour ID</th><th>Year</th></tr>";
            while($row = $result->fetch_assoc()) {
                echo "<tr><td>" . $row["FirstName"] . "</td><td>" . $row["LastName"] . "</td><td>" . $row["TourID"] . "</td><td>" . $row["Year"] . "</td></tr>";
            }
            echo "</table>";
        } else {
            echo "0 results";
        }

        // Free the result set
        $result->free();
    ?> 
    </body> 
</html> 

<?php 
    // Step 4: Close Database
    $conn->close(); 
?>
