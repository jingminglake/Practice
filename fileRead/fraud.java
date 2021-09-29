package com.paypal.risk.fraudevaluation.model;

import java.util.Objects;
import java.util.ArrayList;
import com.fasterxml.jackson.annotation.*;
import com.paypal.risk.fraudevaluation.model.Address;
import com.paypal.risk.fraudevaluation.model.Email;
import com.paypal.risk.fraudevaluation.model.Name;
import com.paypal.risk.fraudevaluation.model.Phone;
import com.paypal.risk.fraudevaluation.model.Verification;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import javax.validation.constraints.*;
import javax.validation.Valid;

@javax.annotation.Generated(value = "com.paypal.ppaas.swagger.codegen.PPaaSJAXRSSwaggerCodegen", date = "2019-01-29T10:47:21.659-08:00")
@JsonInclude(value = JsonInclude.Include.NON_NULL)
@JsonIgnoreProperties(ignoreUnknown = true)
public class Party extends Verification  {

    /**
     * Paypal party type
     */
    @JsonProperty("type")
    private String type = null;

    /**
     * User 2.0 model identifier for party ( currently account_number )
     */
    @JsonProperty("id")
    private String id = null;

    /**
     * external identifier for a party
     */
    @JsonProperty("external_id")
    private String externalId = null;

    /**
     * Account user name.
     */
    @JsonProperty("name")
    @Valid
    private Name name = null;

    /**
     * Indicates if the party in the relationship is the primary Party for that Account
     */
    @JsonProperty("primary")
    private Boolean primary = null;

    /**
     * Email addresses
     */
    @JsonProperty("emails")
    @Valid
    @Size(min=0, max=100, message = "INVALID_ARRAY_LENGTH")
    private List<Email> emails = new ArrayList<>();

    /**
     * Details of user&#39;s phone numbers
     */
    @JsonProperty("phones")
    @Valid
    @Size(min=0, max=100, message = "INVALID_ARRAY_LENGTH")
    private List<Phone> phones = new ArrayList<>();

    /**
     * The [two-character ISO 3166-1 code](/docs/integration/direct/rest/country-codes/) that identifies the country or region.&lt;blockquote&gt;&lt;strong&gt;Note:&lt;/strong&gt; The country code for Great Britain is &lt;code&gt;GB&lt;/code&gt; and not &lt;code&gt;UK&lt;/code&gt; as used in the top-level domain names for that country. Use the &#x60;C2&#x60; country code for China worldwide for comparable uncontrolled price (CUP) method, bank card, and cross-border transactions.&lt;/blockquote&gt;
     */
    @JsonProperty("citizenship")
    @Pattern(regexp = "^([A-Z]{2}|C2)$", message = "INVALID_PARAMETER_SYNTAX")
    @Size(min = 2, max = 2, message = "INVALID_STRING_LENGTH")
    private String citizenship = null;

    /**
     * Details of user&#39;s addresses
     */
    @JsonProperty("addresses")
    @Valid
    @Size(min=0, max=100, message = "INVALID_ARRAY_LENGTH")
    private List<Address> addresses = new ArrayList<>();

    /**
     * The stand-alone date, in [Internet date and time format](https://tools.ietf.org/html/rfc3339#section-5.6). To represent special legal values, such as a date of birth, you should use dates with no associated time or time-zone data. Whenever possible, use the standard &#x60;date_time&#x60; type. This regular expression does not validate all dates. For example, February 31 is valid and nothing is known about leap years.
     */
    @JsonProperty("birth_date")
    @Pattern(regexp = "^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$", message = "INVALID_PARAMETER_SYNTAX")
    @Size(min = 10, max = 10, message = "INVALID_STRING_LENGTH")
    private String birthDate = null;

    /**
     * The date and time, in [Internet date and time format](https://tools.ietf.org/html/rfc3339#section-5.6). Seconds are required while fractional seconds are optional.&lt;blockquote&gt;&lt;strong&gt;Note:&lt;/strong&gt; The regular expression provides guidance but does not reject all invalid dates.&lt;/blockquote&gt;
     */
    @JsonProperty("create_time")
    @Pattern(regexp = "^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])[T,t]([0-1][0-9]|2[0-3]):[0-5][0-9]:([0-5][0-9]|60)([.][0-9]+)?([Zz]|[+-][0-9]{2}:[0-9]{2})$", message = "INVALID_PARAMETER_SYNTAX")
    @Size(min = 20, max = 64, message = "INVALID_STRING_LENGTH")
    private String createTime = null;

    //region Getters & Setters
    public String getType() {
        return type;
    }
    public void setType(String type) {
        this.type = type;
    }

    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }

    public String getExternalId() {
        return externalId;
    }
    public void setExternalId(String externalId) {
        this.externalId = externalId;
    }

    public Name getName() {
        return name;
    }
    public void setName(Name name) {
        this.name = name;
    }

    public Boolean isPrimary() {
        return primary;
    }
    public void setPrimary(Boolean primary) {
        this.primary = primary;
    }

    public List<Email> getEmails() {
        return emails;
    }
    public void setEmails(List<Email> emails) {
        this.emails = emails;
    }

    public List<Phone> getPhones() {
        return phones;
    }
    public void setPhones(List<Phone> phones) {
        this.phones = phones;
    }

    public String getCitizenship() {
        return citizenship;
    }
    public void setCitizenship(String citizenship) {
        this.citizenship = citizenship;
    }

    public List<Address> getAddresses() {
        return addresses;
    }
    public void setAddresses(List<Address> addresses) {
        this.addresses = addresses;
    }

    public String getBirthDate() {
        return birthDate;
    }
    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    public String getCreateTime() {
        return createTime;
    }
    public void setCreateTime(String createTime) {
        this.createTime = createTime;
    }


    //endregion


    //region Utilities

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Party
        party = (Party) o;
            return Objects.equals(type, party.type) &&
        Objects.equals(id, party.id) &&
        Objects.equals(externalId, party.externalId) &&
        Objects.equals(name, party.name) &&
        Objects.equals(primary, party.primary) &&
        Objects.equals(emails, party.emails) &&
        Objects.equals(phones, party.phones) &&
        Objects.equals(citizenship, party.citizenship) &&
        Objects.equals(addresses, party.addresses) &&
        Objects.equals(birthDate, party.birthDate) &&
        Objects.equals(createTime, party.createTime);
    }

    @Override
    public int hashCode() {
        return Objects.hash(type, id, externalId, name, primary, emails, phones, citizenship, addresses, birthDate, createTime);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("class Party {\n");
        sb.append("    ").append(toIndentedString(super.toString())).append("\n");
        sb.append("    type: ").append(toIndentedString(type)).append("\n");
        sb.append("    id: ").append(toIndentedString(id)).append("\n");
        sb.append("    externalId: ").append(toIndentedString(externalId)).append("\n");
        sb.append("    name: ").append(toIndentedString(name)).append("\n");
        sb.append("    primary: ").append(toIndentedString(primary)).append("\n");
        sb.append("    emails: ").append(toIndentedString(emails)).append("\n");
        sb.append("    phones: ").append(toIndentedString(phones)).append("\n");
        sb.append("    citizenship: ").append(toIndentedString(citizenship)).append("\n");
        sb.append("    addresses: ").append(toIndentedString(addresses)).append("\n");
        sb.append("    birthDate: ").append(toIndentedString(birthDate)).append("\n");
        sb.append("    createTime: ").append(toIndentedString(createTime)).append("\n");
        sb.append("}");
        return sb.toString();
    }

    /**
    * Convert the given object to string with each line indented by 4 spaces
    * (except the first line).
    */
    private String toIndentedString(Object o) {
        if (o == null) {
            return "null";
        }
        return o.toString().replace("\n", "\n    ");
    }
}
