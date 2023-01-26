#include "tablerow.h"

TableRow::TableRow( std::vector<std::unique_ptr<SqlCType>> _columns )
    : columns( std::move( _columns ) ) {

    for ( size_t i = 0; i < columns.size(); ++i ) {
        fields.emplace_back( columns[i].get() );
    }
}

void TableRow::displayFields() {
    puts( "" );
    std::cout << std::left << std::setw( 30 ) << "Field Name";
    std::cout << std::left << std::setw( 30 ) << "Field Type";
    std::cout << std::left << std::setw( 30 ) << "Field Value" << '\n';
    std::cout << std::left << std::setw( 90 ) << std::setfill( '-' ) << '-'
              << std::setfill( ' ' ) << '\n';
    std::for_each( fields.begin(), fields.end(), [&]( const auto& o ) {
        std::cout << std::left << std::setw( 30 ) << o->fieldName;
        std::cout << std::left << std::setw( 30 ) << fieldTypes[o->bufferType];
        o->printValue();
        std::cout << std::endl;
    } );
    puts( "" );
}

void TableRow::setBinds(
    const std::optional<std::initializer_list<bool>>& selectedColumns ) {
    if ( selectedColumns.has_value() ) {

        auto& sc = selectedColumns.value();
        if ( sc.size() != columns.size() ) {
            throw std::runtime_error(
                "Incorrect qty of bools given to setBinds() method, must match the "
                "qty of table columns\n" );
        }
        int i = 0;
        std::for_each( sc.begin(), sc.end(),
                       [&]( const bool b ) { columns[i++]->is_selected = b; } );
    }
    selection.erase( selection.begin(), selection.end() );

    std::for_each( columns.begin(), columns.end(), [&]( auto& o ) {
        if ( o->is_selected ) {
            selection.emplace_back();
            o->setBind( &( *std::next( selection.end(), -1 ) ) );
        }
    } );
}
