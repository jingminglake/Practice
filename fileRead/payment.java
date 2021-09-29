package com.paypal.risk.paymentevaluation.model;

import java.util.Objects;
import java.util.ArrayList;
import com.fasterxml.jackson.annotation.*;
import com.paypal.risk.paymentevaluation.model.Address;
import com.paypal.risk.paymentevaluation.model.Email;
import com.paypal.risk.paymentevaluation.model.Name;
import com.paypal.risk.paymentevaluation.model.Name2;
import com.paypal.risk.paymentevaluation.model.PartyRole;
import com.paypal.risk.paymentevaluation.model.PartyType;
import com.paypal.risk.paymentevaluation.model.Phone;
import com.paypal.risk.paymentevaluation.model.VerificationDetail;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import javax.validation.constraints.*;
import javax.validation.Valid;

@javax.annotation.Generated(value = "com.paypal.ppaas.swagger.codegen.PPaaSJAXRSSwaggerCodegen", date = "2018-12-04T21:59:28.670-08:00")
@JsonInclude(value = JsonInclude.Include.NON_NULL)
@JsonIgnoreProperties(ignoreUnknown = true)
public class Party   {

    /**
     * Paypal party type like PERSON, BUSINESS
     */
    @JsonProperty("party_type")
    @Valid
    private PartyType partyType = null;

    /**
     * User 2.0 model identifier for party ( currently account_number )
     */
    @JsonProperty("party_id")
    private String partyId = null;

    /**
     * THIS FIELD IS DEPRECATED PLEASE USE PARTY_NAME FIELD
     */
    @JsonProperty("user_name")
    @Valid
    private Name userName = null;

    /**
     * Account user name.
     */
    @JsonProperty("party_name")
    @Valid
    private Name2 partyName = null;

    /**
     * role of the party
     */
    @JsonProperty("party_role")
    @Valid
    private PartyRole partyRole = null;

    /**
     * Indicates if the party in the relationship is the primary Party for that Account
     */
    @JsonProperty("primary")
    private Boolean primary = null;

    /**
     * A valid internationalized email address, as defined by RFC 5322, RFC 6530, and other RFCs.&lt;blockquote&gt;&lt;strong&gt;Note:&lt;/strong&gt; Due to RFC 5321, 254 is the generally accepted maximum length for an email address even though up to 64 characters are allowed before and 255 characters are allowed after the &lt;code&gt;@&lt;/code&gt; sign. The pattern here only verifies that an unquoted &lt;code&gt;@&lt;/code&gt; sign exists. Services should not rely on static validation of email addresses. The only sure way to validated an email address is to send email to it.&lt;/blockquote&gt;
     */
    @JsonProperty("primary_email_address")
    @Pattern(regexp = "^.+@[^\"\\-].+$", message = "INVALID_PARAMETER_SYNTAX")
    @Size(min = 3, max = 254, message = "INVALID_STRING_LENGTH")
    private String primaryEmailAddress = null;

    /**
     * Primary Email address
     */
    @JsonProperty("party_email")
    @Valid
    private Email partyEmail = null;

    /**
     * THIS FIELD IS DEPRECATED PLEASE USE PARTY_PHONES FIELD
     */
    @JsonProperty("party_phone")
    @Valid
    private Phone partyPhone = null;

    /**
     * Details of user&#39;s phone numbers
     */
    @JsonProperty("party_phones")
    @Valid
    private List<Phone> partyPhones = new ArrayList<>();

    /**
     * The [two-character ISO 3166-1 code](https://developer.paypal.com/docs/classic/api/country_codes/) that identifies the country or region.&lt;blockquote&gt;&lt;strong&gt;Note:&lt;/strong&gt; The country code for Great Britain is &lt;code&gt;GB&lt;/code&gt; and not &lt;code&gt;UK&lt;/code&gt; as used in the top-level domain names for that country. Use the &lt;code&gt;C2&lt;/code&gt; country code for &lt;code&gt;CHINA WORLDWIDE&lt;/code&gt; for CUP, bank card, and cross-border transactions.&lt;/blockquote&gt;
     */
    @JsonProperty("citizenship")
    @Pattern(regexp = "^([A-Z]{2}|C2)$", message = "INVALID_PARAMETER_SYNTAX")
    @Size(min = 2, max = 2, message = "INVALID_STRING_LENGTH")
    private String citizenship = null;

    /**
     * THIS FIELD IS DEPRECATED PLEASE USE PARTY_ADDRESSES FIELD
     */
    @JsonProperty("party_address")
    @Valid
    private Address partyAddress = null;

    /**
     * Details of Account user&#39;s addresses
     */
    @JsonProperty("party_addresses")
    @Valid
    private List<Address> partyAddresses = new ArrayList<>();

    /**
     * A standalone date, as represented by the full-date chunk specified in RFC 3339, section 5.6. Dates with no associated time or time-zone data SHOULD be used to represent special legal values, such as date of birth. Implementers SHOULD consider using the standard date_time schema whenever possible instead. Note that this regular expression is not a complete validation: February 31, for example, is allowed, and nothing is known about leap years.
     */
    @JsonProperty("birth_date")
    @Pattern(regexp = "^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$", message = "INVALID_PARAMETER_SYNTAX")
    @Size(min = 10, max = 10, message = "INVALID_STRING_LENGTH")
    private String birthDate = null;

    /**
     * Details of verification done against this party
     */
    @JsonProperty("verification_details")
    @Valid
    private List<VerificationDetail> verificationDetails = new ArrayList<>();

    /**
     * A valid date-time representation, as defined by RFC 3339, section 5.6.&lt;blockquote&gt;&lt;strong&gt;Note:&lt;/strong&gt; The regular expression cannot reject all invalid dates but only provide guidance. Unlike RFC 3339, we do define a practical if impractically precise length limit on the number of fractional seconds. RFC 3339 is a profile of the ISO 8601 date-time standard. This means, for instance, that seconds are mandatory while fractional seconds are not.&lt;/blockquote&gt;
     */
    @JsonProperty("create_time")
    @Pattern(regexp = "^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])[T,t]([0-1][0-9]|2[0-3]):[0-5][0-9]:([0-5][0-9]|60)([.][0-9]+)?([Zz]|[+-][0-9]{2}:[0-9]{2})$", message = "INVALID_PARAMETER_SYNTAX")
    @Size(min = 20, max = 64, message = "INVALID_STRING_LENGTH")
    private String createTime = null;

    //region Getters & Setters
    public PartyType getPartyType() {
        return partyType;
    }
    public void setPartyType(PartyType partyType) {
        this.partyType = partyType;
    }

    public String getPartyId() {
        return partyId;
    }
    public void setPartyId(String partyId) {
        this.partyId = partyId;
    }

    public Name getUserName() {
        return userName;
    }
    public void setUserName(Name userName) {
        this.userName = userName;
    }

    public Name2 getPartyName() {
        return partyName;
    }
    public void setPartyName(Name2 partyName) {
        this.partyName = partyName;
    }

    public PartyRole getPartyRole() {
        return partyRole;
    }
    public void setPartyRole(PartyRole partyRole) {
        this.partyRole = partyRole;
    }

    public Boolean isPrimary() {
        return primary;
    }
    public void setPrimary(Boolean primary) {
        this.primary = primary;
    }

    public String getPrimaryEmailAddress() {
        return primaryEmailAddress;
    }
    public void setPrimaryEmailAddress(String primaryEmailAddress) {
        this.primaryEmailAddress = primaryEmailAddress;
    }

    public Email getPartyEmail() {
        return partyEmail;
    }
    public void setPartyEmail(Email partyEmail) {
        this.partyEmail = partyEmail;
    }

    public Phone getPartyPhone() {
        return partyPhone;
    }
    public void setPartyPhone(Phone partyPhone) {
        this.partyPhone = partyPhone;
    }

    public List<Phone> getPartyPhones() {
        return partyPhones;
    }
    public void setPartyPhones(List<Phone> partyPhones) {
        this.partyPhones = partyPhones;
    }

    public String getCitizenship() {
        return citizenship;
    }
    public void setCitizenship(String citizenship) {
        this.citizenship = citizenship;
    }

    public Address getPartyAddress() {
        return partyAddress;
    }
    public void setPartyAddress(Address partyAddress) {
        this.partyAddress = partyAddress;
    }

    public List<Address> getPartyAddresses() {
        return partyAddresses;
    }
    public void setPartyAddresses(List<Address> partyAddresses) {
        this.partyAddresses = partyAddresses;
    }

    public String getBirthDate() {
        return birthDate;
    }
    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    public List<VerificationDetail> getVerificationDetails() {
        return verificationDetails;
    }
    public void setVerificationDetails(List<VerificationDetail> verificationDetails) {
        this.verificationDetails = verificationDetails;
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
            return Objects.equals(partyType, party.partyType) &&
        Objects.equals(partyId, party.partyId) &&
        Objects.equals(userName, party.userName) &&
        Objects.equals(partyName, party.partyName) &&
        Objects.equals(partyRole, party.partyRole) &&
        Objects.equals(primary, party.primary) &&
        Objects.equals(primaryEmailAddress, party.primaryEmailAddress) &&
        Objects.equals(partyEmail, party.partyEmail) &&
        Objects.equals(partyPhone, party.partyPhone) &&
        Objects.equals(partyPhones, party.partyPhones) &&
        Objects.equals(citizenship, party.citizenship) &&
        Objects.equals(partyAddress, party.partyAddress) &&
        Objects.equals(partyAddresses, party.partyAddresses) &&
        Objects.equals(birthDate, party.birthDate) &&
        Objects.equals(verificationDetails, party.verificationDetails) &&
        Objects.equals(createTime, party.createTime);
    }

    @Override
    public int hashCode() {
        return Objects.hash(partyType, partyId, userName, partyName, partyRole, primary, primaryEmailAddress, partyEmail, partyPhone, partyPhones, citizenship, partyAddress, partyAddresses, birthDate, verificationDetails, createTime);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("class Party {\n");
        
        sb.append("    partyType: ").append(toIndentedString(partyType)).append("\n");
        sb.append("    partyId: ").append(toIndentedString(partyId)).append("\n");
        sb.append("    userName: ").append(toIndentedString(userName)).append("\n");
        sb.append("    partyName: ").append(toIndentedString(partyName)).append("\n");
        sb.append("    partyRole: ").append(toIndentedString(partyRole)).append("\n");
        sb.append("    primary: ").append(toIndentedString(primary)).append("\n");
        sb.append("    primaryEmailAddress: ").append(toIndentedString(primaryEmailAddress)).append("\n");
        sb.append("    partyEmail: ").append(toIndentedString(partyEmail)).append("\n");
        sb.append("    partyPhone: ").append(toIndentedString(partyPhone)).append("\n");
        sb.append("    partyPhones: ").append(toIndentedString(partyPhones)).append("\n");
        sb.append("    citizenship: ").append(toIndentedString(citizenship)).append("\n");
        sb.append("    partyAddress: ").append(toIndentedString(partyAddress)).append("\n");
        sb.append("    partyAddresses: ").append(toIndentedString(partyAddresses)).append("\n");
        sb.append("    birthDate: ").append(toIndentedString(birthDate)).append("\n");
        sb.append("    verificationDetails: ").append(toIndentedString(verificationDetails)).append("\n");
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
