## memory_allocation.jl
#
## Author: Tom Price
## Date: January 2019
#
## Analyse memory usage in dispatch calls
## See https://docs.julialang.org/en/v0.6/manual/profile/#Memory-allocation-analysis-1
## Usage: julia --track-allocation=user memory_allocation.jl

import DataStructures: OrderedDict
import BSON: load


# performance is better with dispatch calls
# in a function rather than global scope
function test_memory_allocation()
    # load dispatch calls & associated data
    test_functions = BSON.load("../test/data/dispatch_tests.bson")
    #
    # perform calls to force compilation
    check = test_dispatch(test_functions)
    println(check)
    #
    # all test results must be positive, or else an error will be raised
    @assert all(values(check))
    #
    # reset allocation counters
    Profile.clear_malloc_data()
    #
    # execute dispatch calls a second time
    check = test_dispatch(test_functions)
end


# main code >>
autorun = joinpath(Base.JULIA_HOME,Base.SYSCONFDIR,"julia/juliarc.jl")
if all(map(
    x->match(r"6004dbc584427ce1297c8e89e547057e",x)==nothing, # look for magic number
    readlines(autorun)))
    # run these three commands which have not been included in the startup script:
    cd("/home/vagrant/chaipcr/bioinformatics/QpcrAnalysis")
    push!(LOAD_PATH,pwd())
    using QpcrAnalysis
end
include("../test/test_functions.jl") # need test_dispatch()
test_memory_allocation()
# << main code



#
