
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name trafficlight -dir "D:/eductaion/DCSE/6th Semester/DSD Lab/lab12/trafficlight/planAhead_run_1" -part xc6slx9csg324-2
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/eductaion/DCSE/6th Semester/DSD Lab/lab12/trafficlight/Traffic_lights.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/eductaion/DCSE/6th Semester/DSD Lab/lab12/trafficlight} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "Traffic_lights.ucf" [current_fileset -constrset]
add_files [list {Traffic_lights.ucf}] -fileset [get_property constrset [current_run]]
link_design
