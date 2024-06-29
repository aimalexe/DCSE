<!-- 
    Write PHP-MYSQLI Object-Oriented interface script that connects with one of the tables of your 
DBMS Lab Project (For instance, user table or accounts table or any of your choice). Perform the 
following: 
a. Apply the insert command on the table. Take the data from user via HTML Form 
constructs. 
b. Apply the update command on the table. Take the data from user via HTML Form 
constructs. 
c. Apply the delete query on the table. Take the data from user via HTML Form constructs. 
d. Apply the select query on the same table to retrieve data. Show the data in HTML Form 
Constructs.
 -->

<?php 
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

    echo "Connected successfully<br/>";

    // Insert data
    if (isset($_POST['insert'])) {
        $firstName = $_POST['firstName'];
        $lastName = $_POST['lastName'];

        $stmt = $conn->prepare("INSERT INTO member (FirstName, LastName) VALUES (?, ?)");
        $stmt->bind_param("ss", $firstName, $lastName);
        $stmt->execute();
        echo "New records created successfully<br/>";
    }

    // Update data
    if (isset($_POST['update'])) {
        $memberID = $_POST['memberID'];
        $firstName = $_POST['firstName'];

        $stmt = $conn->prepare("UPDATE member SET FirstName = ? WHERE MemberID = ?");
        $stmt->bind_param("si", $firstName, $memberID);
        $stmt->execute();
        echo "Record updated successfully<br/>";
    }

    // Delete data
    if (isset($_POST['delete'])) {
        $memberID = $_POST['memberID'];

        $stmt = $conn->prepare("DELETE FROM member WHERE MemberID = ?");
        $stmt->bind_param("i", $memberID);
        $stmt->execute();
        echo "Record deleted successfully<br/>";
    }

    // Select data
    if (isset($_POST['select'])) {
        $result = $conn->query("SELECT * FROM member");

        if ($result->num_rows > 0) {
            echo "<table border='1'><tr><th>ID</th><th>First Name</th><th>Last Name</th></tr>";
            while ($row = $result->fetch_assoc()) {
                echo "<tr><td>" . $row["MemberID"] . "</td><td>" . htmlspecialchars($row["FirstName"]) . "</td><td>" . htmlspecialchars($row["LastName"]) . "</td></tr>";
            }
            echo "</table>";
        } else {
            echo "0 results";
        }
    }
    $conn->close();
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Lab 6. Task 2</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                margin: 40px;
            }

            h2 {
                color: #333;
            }

            form {
                background: #fff;
                padding: 20px;
                border-radius: 8px;
                box-shadow: 0 2px 4px rgba(0,0,0,0.1);
                margin-bottom: 20px;
            }

            input[type="text"], input[type="number"] {
                width: calc(100% - 22px);
                padding: 10px;
                margin-top: 8px;
                margin-bottom: 16px;
                border: 1px solid #ddd;
                border-radius: 4px;
            }

            input[type="submit"] {
                background-color: #5cb85c;
                color: white;
                border: none;
                padding: 10px 20px;
                border-radius: 4px;
                cursor: pointer;
                font-size: 16px;
            }

            input[type="submit"]:hover {
                background-color: #4cae4c;
            }

            table {
                width: 100%;
                margin-top: 20px;
                border-collapse: collapse;
            }

            table, th, td {
                border: 1px solid #ccc;
            }

            th, td {
                text-align: left;
                padding: 8px;
            }

            th {
                background-color: #eee;
            }
        </style>
    </head>
    <body>
        <h2>Insert Member</h2>
        <form method="post">
            First Name: <input type="text" name="firstName" required><br>
            Last Name: <input type="text" name="lastName" required><br>
            <input type="submit" name="insert" value="Insert Data">
        </form>

        <h2>Update Member</h2>
        <form method="post">
            Member ID: <input type="number" name="memberID" required><br>
            New First Name: <input type="text" name="firstName" required><br>
            <input type="submit" name="update" value="Update Data">
        </form>

        <h2>Delete Member</h2>
        <form method="post">
            Member ID: <input type="number" name="memberID" required><br>
            <input type="submit" name="delete" value="Delete Data">
        </form>

        <h2>Select Members</h2>
        <form method="post">
            <input type="submit" name="select" value="Show Members">
        </form>
    </body>
</html>
