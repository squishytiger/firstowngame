#ifndef Resource_holder_h
#define Resource_holder_h

#include <string>
#include <cassert>
#include <memory>
#include <map>
#include <stdexcept>

template <typename Identifier, typename Resource>
class Resource_holder {
    public:
        void load(Identifier resource_id, const std::string& filename);
        template <typename Parameter>
        void load(Identifier resource_id, const std::string& filename,
                const Parameter& second_param);

        Resource& get(Identifier resource_id);
        const Resource& get(Identifier resource_id) const;

    private:
        std::map<Identifier, std::unique_ptr<Resource>> resource_map;
        void insert_resource(Identifier resource_id, std::unique_ptr<Resource> resource);
};

#include "Resource_holder.inl"

#endif
