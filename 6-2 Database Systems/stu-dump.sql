-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: stu
-- ------------------------------------------------------
-- Server version	5.7.17-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `course`
--

DROP TABLE IF EXISTS `course`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `course` (
  `course_no` varchar(3) NOT NULL,
  `course_name` varchar(12) DEFAULT NULL,
  `hours` int(11) DEFAULT NULL,
  `credit` int(11) DEFAULT NULL,
  `semester` varchar(2) DEFAULT NULL,
  PRIMARY KEY (`course_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `course`
--

LOCK TABLES `course` WRITE;
/*!40000 ALTER TABLE `course` DISABLE KEYS */;
INSERT INTO `course` VALUES ('C01','编译原理',51,3,'秋 '),('C02','数据库原理',51,3,'春 '),('C03','操作系统',51,2,'秋 '),('C04','JAVA 程序设计',40,2,'秋 '),('C05','计算机组成原理',30,2,'春 ');
/*!40000 ALTER TABLE `course` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `info_sel`
--

DROP TABLE IF EXISTS `info_sel`;
/*!50001 DROP VIEW IF EXISTS `info_sel`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `info_sel` AS SELECT 
 1 AS `stu_no`,
 1 AS `stu_name`,
 1 AS `dept`,
 1 AS `course_no`,
 1 AS `course_name`,
 1 AS `grade`,
 1 AS `class_no`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `sel`
--

DROP TABLE IF EXISTS `sel`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sel` (
  `stu_no` varchar(6) NOT NULL,
  `course_no` varchar(3) NOT NULL,
  `grade` int(11) DEFAULT NULL,
  PRIMARY KEY (`stu_no`,`course_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sel`
--

LOCK TABLES `sel` WRITE;
/*!40000 ALTER TABLE `sel` DISABLE KEYS */;
INSERT INTO `sel` VALUES ('30201','C03',40),('30201','C04',88),('30201','C05',93),('30202','C03',40),('30202','C04',40),('30203','C03',57),('30203','C04',50),('30203','C05',40),('30204','C03',54),('30204','C04',50),('30204','C05',40),('30206','C03',40),('30206','C04',40),('30206','C05',50),('30207','C03',82),('30207','C04',40),('30207','C05',40),('30208','C03',40),('30208','C04',40),('30208','C05',97),('30209','C03',40),('30209','C04',88),('30210','C05',40),('30211','C04',40),('30212','C03',50),('30212','C04',91),('30212','C05',40),('30213','C03',88),('30213','C05',59),('30214','C03',50),('30214','C04',50),('30214','C05',40),('30215','C03',40),('30215','C04',61),('30215','C05',50),('30216','C03',40),('30216','C04',53),('30216','C05',50),('30217','C05',66),('30218','C03',40),('30218','C04',60),('30218','C05',40),('30219','C03',95),('30219','C04',40),('30219','C05',40),('30220','C03',68),('30220','C04',87),('30220','C05',40),('30221','C03',40),('30221','C04',50),('30221','C05',40),('30222','C03',53),('30222','C04',60),('30222','C05',50),('30223','C03',83),('30223','C04',53),('30223','C05',40),('30224','C04',90),('30224','C05',40),('30225','C03',40),('30225','C04',40),('30225','C05',50),('30226','C03',40),('30226','C04',40),('30226','C05',50),('30227','C03',50),('30227','C05',82),('30228','C03',83),('30228','C04',59),('30228','C05',40),('31401','C01',94),('31401','C02',65),('31401','C03',0),('31402','C01',40),('31402','C03',0),('31403','C01',40),('31403','C02',84),('31403','C03',40),('31404','C01',40),('31404','C02',40),('31404','C03',98),('31405','C01',40),('31405','C03',60),('31406','C01',40),('31406','C02',86),('31406','C03',40),('31407','C01',40),('31407','C02',92),('31407','C03',65),('31408','C01',40),('31408','C02',40),('31408','C03',40),('31409','C01',40),('31409','C02',40),('31409','C03',65),('31410','C03',40),('31411','C01',97),('31411','C02',61),('31411','C03',50),('31412','C01',40),('31412','C02',40),('31412','C03',56),('31413','C01',91),('31413','C03',40),('31414','C01',40),('31414','C02',94),('31414','C03',53),('31415','C01',40),('31415','C02',40),('31415','C03',50),('31416','C01',40),('31416','C02',63),('31417','C01',97),('31417','C02',94),('31417','C03',40),('31418','C01',55),('31418','C02',93),('31418','C03',50),('31419','C01',86),('31419','C02',40),('31419','C03',88),('31420','C01',40),('31420','C02',40),('31420','C03',57),('31422','C01',40),('31422','C02',85),('31422','C03',40),('31423','C01',40),('31423','C02',40),('31423','C03',40),('31424','C01',40),('31424','C02',88),('31424','C03',92),('31425','C02',40),('31426','C01',40),('31426','C02',96),('31426','C03',40),('31427','C01',40),('31427','C02',88),('31428','C01',40),('31428','C02',40),('31428','C03',40);
/*!40000 ALTER TABLE `sel` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `stu_no` varchar(6) NOT NULL,
  `stu_name` varchar(8) DEFAULT NULL,
  `sex` varchar(2) DEFAULT NULL,
  `b_date` datetime DEFAULT NULL,
  `dept` varchar(8) DEFAULT NULL,
  `class_no` varchar(4) DEFAULT NULL,
  PRIMARY KEY (`stu_no`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES ('30201','吴磊','男','1980-01-02 00:00:00','电信','3022'),('30202','袁青春','男','1980-01-02 00:00:00','电信','3022'),('30203','唐雷','男','1980-01-02 00:00:00','电信','3022'),('30204','吴霏','男','1980-01-02 00:00:00','电信','3022'),('30206','连洪炽','男','1980-01-02 00:00:00','电信','3022'),('30207','王金柱','男','1980-01-02 00:00:00','电信','3022'),('30208','苏广学','男','1980-01-02 00:00:00','电信','3022'),('30209','唐元亮','男','1980-01-02 00:00:00','电信','3022'),('30210','葛艳杰','男','1980-01-02 00:00:00','电信','3022'),('30211','张永超','男','1980-01-02 00:00:00','电信','3022'),('30212','张伟','男','1980-01-02 00:00:00','电信','3022'),('30213','孙刚','男','1980-01-02 00:00:00','电信','3022'),('30214','车平跃','男','1980-01-02 00:00:00','电信','3022'),('30215','张鑫','男','1980-01-02 00:00:00','电信','3022'),('30216','王凯','男','1980-01-02 00:00:00','电信','3022'),('30217','马涛','男','1980-01-02 00:00:00','电信','3022'),('30218','王佳楠','男','1980-01-02 00:00:00','电信','3022'),('30219','马浩','男','1980-01-02 00:00:00','电信','3022'),('30220','邵苏杰','男','1980-01-02 00:00:00','电信','3022'),('30221','郑建华','男','1980-01-02 00:00:00','电信','3022'),('30222','郑侃彦','男','1980-01-02 00:00:00','电信','3022'),('30223','宁剑霞','女','1980-01-02 00:00:00','电信','3022'),('30224','龙海燕','女','1980-01-02 00:00:00','电信','3022'),('30225','陈菊英','女','1980-01-02 00:00:00','电信','3022'),('30226','李新元','女','1980-01-02 00:00:00','电信','3022'),('30227','郭小莉','女','1980-01-02 00:00:00','电信','3022'),('30228','王倩','女','1980-01-02 00:00:00','电信','3022'),('31401','郭子敬','男','1980-01-02 00:00:00','计算机','3146'),('31402','胡雅杰','男','1980-01-02 00:00:00','计算机','3146'),('31403','杨磊','男','1980-01-02 00:00:00','计算机','3146'),('31404','冯宇宁','男','1980-01-02 00:00:00','计算机','3146'),('31405','黄荣','男','1980-01-02 00:00:00','计算机','3146'),('31406','宋月','男','1980-01-02 00:00:00','计算机','3146'),('31407','赵卫京','男','1980-01-02 00:00:00','计算机','3146'),('31408','刘树魁','男','1980-01-02 00:00:00','计算机','3146'),('31409','牛海锋','男','1980-01-02 00:00:00','计算机','3146'),('31410','吴宁','男','1980-01-02 00:00:00','计算机','3146'),('31411','毛文亮','男','1980-01-02 00:00:00','计算机','3146'),('31412','刘俊亮','男','1980-01-02 00:00:00','计算机','3146'),('31413','李承彧','男','1980-01-02 00:00:00','计算机','3146'),('31414','王朝远','男','1980-01-02 00:00:00','计算机','3146'),('31415','刘琛','男','1980-01-02 00:00:00','计算机','3146'),('31416','徐亮亮','男','1980-01-02 00:00:00','计算机','3146'),('31417','张超','男','1980-01-02 00:00:00','计算机','3146'),('31418','苏旭浩','男','1980-01-02 00:00:00','计算机','3146'),('31419','崔江平','男','1980-01-02 00:00:00','计算机','3146'),('31420','唐飞','男','1980-01-02 00:00:00','计算机','3146'),('31422','林昕','女','1980-01-02 00:00:00','计算机','3146'),('31423','操牡丹','女','1980-01-02 00:00:00','计算机','3146'),('31424','张乐园','无','1980-01-02 00:00:00','计算机','3146'),('31425','雷爽','女','1980-01-02 00:00:00','计算机','3146'),('31426','秦灵伶','女','1980-01-02 00:00:00','计算机','3146'),('31427','黄金花','女','1980-01-02 00:00:00','计算机','3146'),('31428','张敏','女','1980-01-02 00:00:00','计算机','3146');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Final view structure for view `info_sel`
--

/*!50001 DROP VIEW IF EXISTS `info_sel`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `info_sel` AS select `student`.`stu_no` AS `stu_no`,`student`.`stu_name` AS `stu_name`,`student`.`dept` AS `dept`,`course`.`course_no` AS `course_no`,`course`.`course_name` AS `course_name`,`sel`.`grade` AS `grade`,`student`.`class_no` AS `class_no` from ((`student` join `course`) join `sel` on(((`student`.`stu_no` = `sel`.`stu_no`) and (`course`.`course_no` = `sel`.`course_no`)))) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-03-29 20:01:04
