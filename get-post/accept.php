<!DOCTYPE html>
<html>
<head>
	<title>Accept</title>
</head>
<body>
<?php
$nama = $_POST["nama"];
$gender = $_POST["gender"];
$jurusan = $_POST ["jurusan"];
echo "Nama 		: $nama"."<br>";
if($gender=='L'){
	echo "Gender : Laki-Laki";
}
else{
	echo "Gender : Perempuan";
}
echo "<br>";
if($jurusan==0){
	echo "Teknik Informatika";
}
elseif ($jurusan==1) {
	echo "Teknik Komputer";
}
else{
	echo "Sistem Informasi";
}
echo "<br>";
echo "Data telah kami terima"."<br>";
echo "Terima Kasih";
?>
</body>
</html>
