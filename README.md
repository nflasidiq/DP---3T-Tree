<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DP-3T Simulation Program</title>
</head>
<body>

<h1>Program Simulasi DP-3T</h1>

<h2>Definisi</h2>
<p>DP-3T (Decentralized Privacy-Preserving Proximity Tracing) merupakan suatu metode kriptografi untuk menyembunyikan identitas. Secara esensial DP-3T berfungsi untuk mengetahui siapa orang yang telah di kontak/melakukan kontak dengan orang tertentu, tanpa harus mengetahui identitas orang yang dimaksud (di kontak/terkontak) secara langsung, sehingga keamanan identitas dari orang yang ditelusuri aman dan terjaga. DP-3T memiliki aplikasi nyata untuk melakukan tracing pada penyebaran virus Covid-19 tanpa menyalahi aturan privasi pengguna handphone.</p>

<h2>Bagaimana DP-3T Bekerja</h2>
<p>Misalkan ada dua orang yang sedang berbincang. Saat berbincang, handphone mereka saling mengirimkan sinyal (device handshake) dan masing-masing handphone mengirimkan ID unik yang disebut EPh-ID. Jika kontak berlangsung lebih dari 10 menit, masing-masing EPh-ID akan disimpan pada database dari user yang bersangkutan. Misalnya, user A dan user B melakukan handshake selama 10 menit, maka EPh-ID user A akan disimpan di database user B dan sebaliknya.</p>

<p>Jika user B bertemu dengan beberapa user lain sepanjang hari, mereka akan mengumpulkan beberapa EPh-ID di database mereka sementara EPh-ID mereka disimpan di database orang-orang yang mereka temui. Jika user B dinyatakan positif Covid-19, EPh-ID mereka akan ditandai sebagai "terinfeksi". User lain dapat memeriksa apakah mereka pernah melakukan kontak dengan EPh-ID yang ada di segmen terinfeksi. Jika ditemukan kecocokan, detail mengenai waktu dan durasi kontak akan ditampilkan, sehingga user dapat memutuskan apakah mereka perlu melakukan tes.</p>

<h2>Implementasi Program</h2>
<p>Untuk mensimulasikan aplikasi DP-3T dalam bahasa pemrograman C, kami akan membuat program yang memodelkan penyebaran infeksi sebagai struktur tree. Tujuannya adalah untuk memungkinkan user melakukan simulasi tracing kontak dan mengidentifikasi siapa yang telah terinfeksi dengan memvisualisasikan tree tersebut.</p>

<h2>Fitur</h2>
<ul>
    <li><strong>Simulasi Kontak User</strong>: User dapat mensimulasikan kontak antara beberapa user, menghasilkan tree yang mewakili transmisi virus.</li>
    <li><strong>Tracing Infeksi</strong>: Mengidentifikasi user yang terinfeksi dan kontak mereka dengan membaca dan menginterpretasikan struktur tree.</li>
    <li><strong>Tingkat Infeksi</strong>: Menghitung dan menampilkan tingkat risiko infeksi untuk setiap user berdasarkan posisi mereka dalam tree.</li>
</ul>

<h2>Alur Penggunaan</h2>
<p>Program ini memiliki dua jenis user: <strong>Admin</strong> dan <strong>User Biasa</strong>. Berikut adalah alur penggunaan untuk masing-masing:</p>

<h3>Admin</h3>
<ul>
    <li><strong>Login</strong>: Admin dapat login dengan akun yang sudah terdaftar.</li>
    <li><strong>Manajemen User</strong>: Admin dapat melihat daftar user yang terdaftar, menambah user baru, menghapus user, dan memperbarui informasi user.</li>
    <li><strong>Monitoring Infeksi</strong>: Admin dapat melihat tree infeksi secara keseluruhan dan memantau status infeksi setiap user.</li>
</ul>

<h3>User Biasa</h3>
<ul>
    <li><strong>Login</strong>: User dapat login dengan akun yang sudah terdaftar. Jika tidak memiliki akun, user harus melakukan registrasi terlebih dahulu.</li>
    <li><strong>Registrasi</strong>: User baru dapat mendaftar dengan mengisi informasi yang diperlukan. Setelah registrasi, user akan memiliki akun untuk login.</li>
    <li><strong>Simulasi Kontak</strong>: User dapat mensimulasikan kontak dengan user lain. Jika kontak berlangsung lebih dari 10 menit, EPh-ID akan disimpan di database masing-masing user.</li>
    <li><strong>Tracing Infeksi</strong>: User dapat memeriksa apakah mereka pernah melakukan kontak dengan user yang terinfeksi dan melihat detail kontak tersebut.</li>
    <li><strong>Melihat Status</strong>: User dapat melihat status infeksi mereka berdasarkan tree infeksi. Jika mereka berada di beberapa tree dengan tingkat infeksi berbeda, tingkat risiko tertinggi akan ditampilkan.</li>
</ul>

<h2>Aturan Tingkat Infeksi</h2>
<p>Kami mendefinisikan tingkat infeksi relatif terhadap user yang terinfeksi:</p>
<ul>
    <li><strong>Level 1</strong>: Risiko infeksi tinggi; segera lakukan screening dengan PCR.</li>
    <li><strong>Level 2</strong>: Risiko infeksi sedang; lakukan screening dengan rapid test.</li>
    <li><strong>Level 3</strong>: Risiko infeksi rendah; disarankan untuk rapid test.</li>
    <li><strong>Level 4+</strong>: Risiko minimal; tidak perlu tindakan khusus.</li>
</ul>
<p>Level ini didasarkan pada asumsi dan observasi sederhana dan tidak merepresentasikan probabilitas infeksi di dunia nyata.</p>

<h2>Kesimpulan</h2>
<p>Program simulasi ini bertujuan untuk meniru aplikasi DP-3T, memberikan cara sederhana namun efektif untuk memvisualisasikan dan melacak penyebaran infeksi. Dengan mengelola data kontak dan tingkat infeksi, user dapat memahami risiko mereka dan mengambil tindakan yang sesuai.</p>

</body>
</html>
