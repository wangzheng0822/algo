lazy val root = (project in file("."))
  .settings(
    name := "algo-scala",
    version := "1.0",
    scalaVersion := "2.12.8",
    libraryDependencies += "org.scalatest" %% "scalatest" % "3.0.5" % "test"
  )
