<?php
header('Content-type:text/html;charset=utf-8');
header("WWW-Authenticate: Basic realm='认证'");
// header('HTTP/1.0 401 Unauthorized');
// echo 'Authorization Required.';
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script>
        function a() {
            document.getElementById("x").innerHTML = document.getElementById("xjj").nodeValue;
        }
    </script>
</head>

<body>
    <script src="../"></script>
    <form method="POST">
        <input type="text" id="xjj">
        <button onclick="a()">提交</button>
    </form>
    <div id="x"></div>
</body>

</html>