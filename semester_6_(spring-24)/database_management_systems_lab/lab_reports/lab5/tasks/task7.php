<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>7: Company Structure</title>
</head>
<body>
    <h1>Employees Information</h1>
    <?php
        $departments = [
            ['depID' => 1, 'depName' => 'Human Resources'],
            ['depID' => 2, 'depName' => 'Marketing'],
            ['depID' => 3, 'depName' => 'Engineering'],
            ['depID' => 4, 'depName' => 'Sales'],
            ['depID' => 5, 'depName' => 'Finance']
        ];
        
        $employees = [
            ['empID' => 1, 'empName' => 'Alice', 'empJob' => 'Recruiter', 'dID' => 1],
            ['empID' => 2, 'empName' => 'Bob', 'empJob' => 'Marketer', 'dID' => 2],
            ['empID' => 3, 'empName' => 'Charlie', 'empJob' => 'Software Engineer', 'dID' => 3],
            ['empID' => 4, 'empName' => 'David', 'empJob' => 'Sales Representative', 'dID' => 4],
            ['empID' => 5, 'empName' => 'Eva', 'empJob' => 'Accountant', 'dID' => 5]
        ];
        
        function getDepartmentName($departments, $depID) {
            foreach ($departments as $department) {
                if ($department['depID'] == $depID) {
                    return $department['depName'];
                }
            }
            return "Department not found";
        }

        function findEmployeesByDepartment($employees, $depID) {
            $deptEmployees = [];
            foreach ($employees as $employee) {
                if ($employee['dID'] == $depID) {
                    $deptEmployees[] = $employee;
                }
            }
            return $deptEmployees;
        }

        function displayEmployees($employees, $departments) {
            foreach ($employees as $employee) {
                $departmentName = getDepartmentName($departments, $employee['dID']);
                echo "Name: " . $employee['empName'] . ", Job: " . $employee['empJob'] . ", Department: " . $departmentName . "<br>";
            }
        }

        displayEmployees($employees, $departments); 
    ?>
</body>
</html>
