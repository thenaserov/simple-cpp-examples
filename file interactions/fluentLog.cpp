void GUI_Main::fluentLog(int connectorID)
{
    // Define log file path
     const std::string directory = "fluentLog";
     const std::string filepath = directory + "/fluentLog.txt";

     // Create directory if it doesn't exist
     std::filesystem::create_directories(directory);

     // Open the file to append each time this function is called
     std::ofstream outfile(filepath, std::ios_base::app);

     if (!outfile.is_open()) {
         std::cerr << "Error opening file for appending." << std::endl;
         return; // Exit if there is an error
     }

     // Generate current time for the log entry
     std::time_t t = std::time(nullptr);
     std::tm tm = *std::localtime(&t);

     // Format the time according to the specified format
     std::ostringstream time_stream;
     std::ostringstream date_stream;
     date_stream << std::put_time(&tm, "%Y-%m-%d");
     time_stream << std::put_time(&tm, "%H:%M:%S");

     // Define fixed and generated values for logging
     std::string charger_id = m_ChargePointIdentifier.toUtf8().constData();
     std::string connector_id = std::to_string(connectorID); // Fixed connector ID
     std::string connector_state = std::to_string(connector_cc.at(connectorID)->getRunState());
     std::string connector_error = std::to_string(connector_cc.at(connectorID)->get_fault_code()); // todo
     std::string termination_code = "T_CODE"; //
     std::string availability_code = std::to_string(connector_cc.at(connectorID)->getAvailabilityStatus());
     std::string board_command = "connector_cc.at(connectorID)";
     std::string warning_code = "charger_data_tag.charging_fault_type";
     std::string panel_pc_state = "ppc_status";
     std::string log_string = "unavailable";
     std::string panel_pc_error = "0";
     std::string panel_pc_warning = "0";
     std::string start_type = connector_cc.at(connectorID)->getLastPacket().toUtf8().constData();
     std::string start_id = "default";
     std::string soc = "80";
     std::string remaining_time = "60";
     std::string voltage = std::to_string(cdata_end[connectorID].voltage[0]);
     std::string current = "10";
     std::string power = std::to_string(std::stod(voltage) * std::stod(current));
     std::string energy = "100";
     std::string max_ev_voltage = "400";
     std::string ev_battery_pack = "1000";
     std::string ev_vin = "vin";
     std::string last_packet_string = connector_cc.at(connectorID)->getLastPacket().toUtf8().constData();

     // Write a single log entry with all necessary data
     outfile << date_stream.str() << "|"
             << time_stream.str() << "|"
             << charger_id << "|"
             << connector_id << "|"
             << connector_state << "|"
             << connector_error << "|"
             << termination_code << "|"
             << availability_code << "|"
             << board_command << "|"
             << warning_code << "|"
             << panel_pc_state << "|"
             << log_string << "|"
             << panel_pc_error << "|"
             << panel_pc_warning << "|"
             << start_type << "|"
             << start_id << "|"
             << soc << "|"
             << remaining_time << "|"
             << voltage << "|"
             << current << "|"
             << power << "|"
             << energy << "|"
             << max_ev_voltage << "|"
             << ev_battery_pack << "|"
             << ev_vin << "|"
             << last_packet_string
             << "\n";

     // Close the file
     outfile.close();
}
