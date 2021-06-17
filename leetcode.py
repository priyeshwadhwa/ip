import os

dirs = """1025_divisor_game
256_paint_house
121_best_time_to_buy_and_sell_stock
746_min_cost_climbing_stairs
392_is_subsequence
70_climbing_stairs
53_maximum_subarray
303_range_sum_query_immutable
198_house_robber
276_paint_fence
1314_matrix_block_sum
1277_count_square_submatrices_with_all_ones
338_counting_bits
750_number_of_corner_rectangles
1130_minimum_cost_tree_from_leaf_values
877_stone_game
1273_delete_tree_nodes
931_minimum_falling_path_sum
1140_stone_game_ii
647_palindromic_substrings
1227_airplane_seat_assignment_probability
1143_longest_common_subsequence
983_minimum_cost_for_tickets
1105_filling_bookcase_shelves
712_minimum_ascii_delete_sum_for_two_strings
413_arithmetic_slices
1055_shortest_way_to_form_string
1066_campus_bikes_ii
1048_longest_string_chain
1027_longest_arithmetic_sequence
714_best_time_to_buy_and_sell_stock_with_transaction_fee
64_minimum_path_sum
1372_longest_zigzag_path_in_a_binary_tree
62_unique_paths
651_4_keys_keyboard
516_longest_palindromic_subsequence
646_maximum_length_of_pair_chain
638_shopping_offers
96_unique_binary_search_trees
343_integer_break
1155_number_of_dice_rolls_with_target_sum
813_largest_sum_of_averages
718_maximum_length_of_repeated_subarray
1024_video_stitching
650_2_keys_keyboard
740_delete_and_earn
357_count_numbers_with_unique_digits
688_knight_probability_in_chessboard
351_android_unlock_patterns
1039_minimum_score_triangulation_of_polygon
873_length_of_longest_fibonacci_subsequence
1230_toss_strange_coins
486_predict_the_winner
838_push_dominoes
494_target_sum
978_longest_turbulent_subarray
1139_largest_1_bordered_square
309_best_time_to_buy_and_sell_stock_with_cooldown
1405_longest_happy_string
764_largest_plus_sign
361_bomb_enemy
1262_greatest_sum_divisible_by_three
279_perfect_squares
698_partition_to_k_equal_sum_subsets
377_combination_sum_iv
1223_dice_roll_simulation
935_knight_dialer
1049_last_stone_weight_ii
120_triangle
1218_longest_arithmetic_subsequence_of_given_difference
416_partition_equal_subset_sum
474_ones_and_zeroes
300_longest_increasing_subsequence
1058_minimize_rounding_error_to_meet_target
375_guess_number_higher_or_lower_ii
95_unique_binary_search_trees_ii
264_ugly_number_ii
376_wiggle_subsequence
1367_linked_list_in_binary_tree
808_soup_servings
139_word_break
967_numbers_with_same_consecutive_differences
801_minimum_swaps_to_make_sequences_increasing
790_domino_and_tromino_tiling
787_cheapest_flights_within_k_stops
1423_maximum_points_you_can_obtain_from_cards
304_range_sum_query_2d_immutable
221_maximal_square
1186_maximum_subarray_sum_with_one_deletion
368_largest_divisible_subset
213_house_robber_ii
898_bitwise_ors_of_subarrays
1339_maximum_product_of_splitted_binary_tree
673_number_of_longest_increasing_subsequence
467_unique_substrings_in_wraparound_string
322_coin_change
576_out_of_boundary_paths
63_unique_paths_ii
837_new_21_game
418_sentence_screen_fitting
152_maximum_product_subarray
5_longest_palindromic_substring
464_can_i_win
1191_k_concatenation_maximum_sum
523_continuous_subarray_sum
91_decode_ways
1402_reducing_dishes
1420_build_array_where_you_can_find_the_maximum_exactly_k_comparisons
1411_number_of_ways_to_paint_n_×_3_grid
1136_parallel_courses
1289_minimum_falling_path_sum_ii
1320_minimum_distance_to_type_a_word_using_two_fingers
1074_number_of_submatrices_that_sum_to_target
1278_palindrome_partitioning_iii
1147_longest_chunked_palindrome_decomposition
1359_count_all_valid_pickup_and_delivery_options
1312_minimum_insertion_steps_to_make_a_string_palindrome
1335_minimum_difficulty_of_a_job_schedule
1340_jump_game_v
982_triples_with_bitwise_and_equal_to_zero
1406_stone_game_iii
960_delete_columns_to_make_sorted_iii
1220_count_vowels_permutation
1259_handshakes_that_don't_cross
1092_shortest_common_supersequence
847_shortest_path_visiting_all_nodes
312_burst_balloons
1240_tiling_a_rectangle_with_the_fewest_squares
903_valid_permutations_for_di_sequence
1216_valid_palindrome_iii
471_encode_string_with_shortest_length
1246_palindrome_removal
920_number_of_music_playlists
1125_smallest_sufficient_team
689_maximum_sum_of_3_non_overlapping_subarrays
265_paint_house_ii
410_split_array_largest_sum
1235_maximum_profit_in_job_scheduling
1373_maximum_sum_bst_in_binary_tree
975_odd_even_jump
1388_pizza_with_3n_slices
964_least_operators_to_express_number
943_find_the_shortest_superstring
514_freedom_trail
72_edit_distance
691_stickers_to_spell_word
1269_number_of_ways_to_stay_in_the_same_place_after_some_steps
1326_minimum_number_of_taps_to_open_to_water_a_garden
472_concatenated_words
1187_make_array_strictly_increasing
730_count_different_palindromic_subsequences
940_distinct_subsequences_ii
546_remove_boxes
727_minimum_window_subsequence
1425_constrained_subset_sum
568_maximum_vacation_days
664_strange_printer
1000_minimum_cost_to_merge_stones
956_tallest_billboard
1349_maximum_students_taking_exam
403_frog_jump
879_profitable_schemes
1067_digit_count_in_range
517_super_washing_machines
818_race_car
115_distinct_subsequences
1012_numbers_with_repeated_digits
1301_number_of_paths_with_max_score
968_binary_tree_cameras
363_max_sum_of_rectangle_no_larger_than_k
123_best_time_to_buy_and_sell_stock_iii
85_maximal_rectangle
1416_restore_the_array
1199_minimum_time_to_build_blocks
552_student_attendance_record_ii
1397_find_all_good_strings
354_russian_doll_envelopes
600_non_negative_integers_without_consecutive_ones
741_cherry_pickup
87_scramble_string
1363_largest_multiple_of_three
446_arithmetic_slices_ii_subsequence
871_minimum_number_of_refueling_stops
902_numbers_at_most_n_given_digit_set
97_interleaving_string
629_k_inverse_pairs_array
140_word_break_ii
132_palindrome_partitioning_ii
174_dungeon_game
656_coin_path
466_count_the_repetitions
32_longest_valid_parentheses
188_best_time_to_buy_and_sell_stock_iv
321_create_maximum_number
887_super_egg_drop
10_regular_expression_matching
639_decode_ways_ii
44_wildcard_matching"""

basedir = R"C:\priyesh_wadhwa\ip\dynamic"

template = """ 
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <regex>
#include <string>
#incluse <sstream>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;

/* Problem:


*/

class Solution {
    public:

};

TEST_CASE("test_success") {
    Solution s;
    REQUIRE(1==1);
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}
"""
for i in dirs.splitlines():
    dir = os.path.join(basedir, i)
    print(dir)
    os.makedirs(dir)
    i = i.split('_',1)
    file = os.path.join(dir, i[1] + ".cpp")
    with open(file, "w") as f:
        f.write(template)
    
