#include <mysql/mysql.h>

#include <fstream>
#include <iostream>
#include <string>

#include "seth_ql.h"

/*
    Example tests out using the BindsArray objects for prepared statements that input and output binary file
    values. It takes 4 images from the photos/ directory ( located in the same example_code/ directory ),
    inserts their data into a table and then retrieves the data for 2 of them to create copies of the images
    in the current directory.
*/

using namespace seth_ql;

// helper functions
std::string get_binary_file_data( const std::string& filename );
void write_binary_file( const std::string& filename, const std::string& buffer );

int main() {
   try {
      MySQLSession::init();
      Connection db_conn( HOST, USER, PASSWORD, DATABASE, 0, "", 0 );
      Query q( db_conn );
      q.execute( "DROP TABLE IF EXISTS image_table" );
      q.execute( "CREATE TABLE image_table(name VARCHAR(50) NOT NULL PRIMARY KEY, image MEDIUMBLOB NOT NULL)" );

      Statement stmt1( db_conn, "INSERT into image_table VALUES(?,?)" );
      auto input = makeInputBindsArray( Bind<Field::VARCHAR>( "name", 50 ), Bind<Field::BLOB>( "image" ) );
      stmt1.bind_param( input.getBinds() );

      input[ "name" ] = "lamp-flame";
      input[ "image" ] = get_binary_file_data( "photos/671-small-lamp-flame.jpg" );
      stmt1.execute();

      input[ "name" ] = "effect-circle";
      input[ "image" ] = get_binary_file_data( "photos/1584361708halftone-effect-circle-freesvg.org.png" );
      stmt1.execute();

      input[ 0 ] = "waterfall";
      input[ 1 ] = get_binary_file_data( "photos/waterfall.jpeg" );
      stmt1.execute();

      input[ 0 ] = "clock-icon";
      input[ 1 ] = get_binary_file_data( "photos/public-domain-icon-set-3.jpg" );
      stmt1.execute();

      Statement stmt2( db_conn, "SELECT image FROM image_table WHERE name=?" );
      input.setBinds( { "name" } );  // only sets the MYSQL_BIND named "name" for binding
      stmt2.bind_param( input.getBinds() );
      auto output = makeOutputBindsArray( Bind<Field::BLOB>( "image" ) );
      stmt2.bind_result( output.getBinds() );

      input[ "name" ] = "lamp-flame";
      stmt2.execute();
      if ( mysql_stmt_fetch( stmt2 ) != 0 ) {
         failOut( "mysql_stmt_fetch( stmt2 )", mysql_error( db_conn ) );
      }
      write_binary_file( "lamp-flame-copy.jpg", output[ "image" ].Value<Field::BLOB>() );

      input[ "name" ] = "effect-circle";
      stmt2.execute();
      if ( mysql_stmt_fetch( stmt2 ) != 0 ) {
         failOut( "mysql_stmt_fetch( stmt2 )", mysql_error( db_conn ) );
      }
      write_binary_file( "effect-circle-copy.png", output[ "image" ].Value<Field::BLOB>() );

      std::cout << "Finished!\n";

   } catch ( std::runtime_error& e ) { std::cerr << e.what(); }

   return 0;
}

std::string get_binary_file_data( const std::string& filename ) {
   std::ifstream file( filename, std::ios::binary | std::ios::ate );
   if ( !file ) {
      std::cerr << "Error: Could not open file " << filename << std::endl;
      failOut( "get_binary_file_data()", "" );
   }

   const std::streamsize size = file.tellg();
   file.seekg( 0, std::ios::beg );

   std::string buffer( size, 0 );
   if ( !file.read( reinterpret_cast<char*>( buffer.data() ), size ) ) {
      std::cerr << "Error: Could not read file " << filename << std::endl;
      failOut( "get_binary_file_data()", "" );
   }

   return buffer;
}

void write_binary_file( const std::string& filename, const std::string& buffer ) {
   std::ofstream file( filename, std::ios::binary );
   if ( !file ) {
      std::cerr << "Error: Could not open file " << filename << std::endl;
      failOut( "write_binary_file()", "" );
   }

   file.write( reinterpret_cast<const char*>( buffer.data() ), buffer.size() );
   file.close();
}
